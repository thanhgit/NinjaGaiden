using Map.MapEditor.DTO;
using Map.MapEditor.FileSys.Object;
using Map.MapEditor.Object;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Map.MapEditor.Quadtree;
using Map.MapEditor.Grid;

namespace Map
{
    public partial class Home : Form
    {

        private const int WM_SCROLL = 276; // Horizontal scroll 
        private const int SB_LINELEFT = 0; // Scrolls one cell left 
        private const int SB_LINERIGHT = 1; // Scrolls one line right

        String folderDefault = "../../images/";

        private int x = 0;
        private int y = 0;

        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        private static extern int SendMessage(IntPtr hWnd, int wMsg, IntPtr wParam, IntPtr lParam);


        private int[,] matrix;
        private int width_map;
        private int height_map;
        private HomeContext context;

        private List<String> enemiesPath = new List<string>();
        private List<String> bossesPath = new List<string>();
        private List<String> itemsPath = new List<string>();

        // enemies
        private List<ObjGame> enemies = new List<ObjGame>();

        // boss
        private List<ObjGame> bosses = new List<ObjGame>();

        // recs
        private List<Rectangle> recs = new List<Rectangle>();

        // items
        private List<Item> itemList = new List<Item>();


        private ObjDTO  selectedObj = null;

        // select obj
        private PictureBox pbObjSelected = null;
        private ObjGame objGameSelected = null;

        private Bitmap bmp_map;

        private Point tlPoint = new Point(-1, -1);
        private Point rbPoint = new Point(-1, -1);

        private List<Rectangle> rectanglesOfQuadtree = new List<Rectangle>();
        private List<QNode> nodes = new List<QNode>();
        private List<Cell> cells = new List<Cell>();

        public Bitmap Bmp_map
        {
            get
            {
                return bmp_map;
            }

            set
            {
                bmp_map = value;
            }
        }

        public Home()
        {
            InitializeComponent();
            context = new HomeContext(this);

            this.MouseWheel += new MouseEventHandler(this.picMap_MouseWheel);            
        }

        private void picMap_MouseMove(object sender, MouseEventArgs e)
        {
            int x_axis = e.X;
            int y_axis = this.height_map - e.Y;
            this.x = e.X;
            this.y = e.Y;
            int col = x / 16;
            int row = y / 16;
            labelCoordinate.Text = "Tọa độ Descartes ( " + x_axis + ", " + y_axis + " ) thuộc ô ( " + col + ", " + row + ")";
            label7.Text = "Tọa độ ( "+this.x+", "+this.y+")";
        }

        private void picMap_MouseWheel(object sender, MouseEventArgs e)
        {
            if (ModifierKeys == Keys.Shift)
            {
                var direction = e.Delta > 0 ? SB_LINELEFT : SB_LINERIGHT;

                SendMessage(this.panelMap.Handle, WM_SCROLL, (IntPtr)direction, IntPtr.Zero);
            }
        }

        private PictureBox pushObjGame(int x, int y, ObjDTO objDTO)
        {
            PictureBox pb = new PictureBox();
            pb.Location = new Point(x, y);
            pb.SizeMode = PictureBoxSizeMode.AutoSize;
            pb.BackColor = Color.Transparent;
            Bitmap bmp = Utils.CreatBitmapTransparent(objDTO.ImagePath);
            pb.Image = bmp;
            pb.Click += new EventHandler(click_pb_obj);
            objDTO.Obj.X = x;
            objDTO.Obj.Y = y;

            picMap.Controls.Add(pb);
            return pb;
        }

        private void picMap_Click(object sender, EventArgs e)
        {
            if (ModifierKeys == Keys.Shift)
            {
                if (this.selectedObj != null)
                {
                    picMap.Controls.Add(pushObjGame(this.x, this.y, this.selectedObj));
                    ObjGame obj = null;
                    if (this.selectedObj.Obj.Type.Equals("enemy"))
                    {
                        obj = new Enemy(this.selectedObj.Obj);
                        this.enemies.Add(obj);
                    }
                    else if (this.selectedObj.Obj.Type.Equals("boss"))
                    {
                        obj = new Boss(this.selectedObj.Obj);
                        this.bosses.Add(obj);
                    }
                    else if (this.selectedObj.Obj.Type.Equals("item"))
                    {
                        Item item = new Item(this.selectedObj.Obj, txtContainer.Text);
                        this.itemList.Add(item);
                    }
                }
                
            }else if(ModifierKeys == Keys.Control)
            {
                if(tlPoint.X == -1 && tlPoint.Y == -1)
                {
                    tlPoint = new Point((this.x / 16) * 16, (this.y / 16) * 16);
                }else if(rbPoint.X == -1 && rbPoint.Y == -1)
                {
                    rbPoint = new Point((this.x / 16 + 1) * 16, (this.y / 16 + 1) * 16);
                    Rectangle rec = new Rectangle(tlPoint.X, tlPoint.Y, rbPoint.X - tlPoint.X, rbPoint.Y - tlPoint.Y);
                    this.recs.Add(rec);
                    tlPoint = new Point(-1,-1);
                    rbPoint = new Point(-1,-1);
                    this.Invalidate(); 
                    this.Update(); 
                    this.Refresh();
                }
            }
        }

        private void click_pb_obj(object sender, EventArgs e)
        {
            PictureBox pb = (PictureBox)sender;
            Rectangle rec = pb.Bounds;

            if (ModifierKeys == Keys.Alt)
            {
                foreach (ObjGame obj in this.enemies)
                {
                    int x = obj.X + (obj.Width / 2);
                    int y = obj.Y + (obj.Height / 2);
                    if (rec.Contains(x, y))
                    {
                        this.enemies.Remove(obj);
                        break;
                    }
                }

                this.picMap.Controls.Remove(pb);

            }
            else
            {
                foreach (ObjGame obj in this.enemies)
                {
                    int x = obj.X + (obj.Width / 2);
                    int y = obj.Y + (obj.Height / 2);
                    if (rec.Contains(x, y))
                    {
                        setObject(obj);
                        this.objGameSelected = obj;
                    }
                }

                foreach (PictureBox _pb in this.picMap.Controls)
                {
                    Rectangle _rec = new Rectangle(_pb.Location.X - _pb.Size.Width/2, _pb.Location.Y + _pb.Size.Height/2, _pb.Size.Width+15, _pb.Size.Height+15);
                    if (_rec.Contains(this.x, this.y))
                    {
                        if (this.pbObjSelected != null)
                        {
                            this.pbObjSelected.BackColor = Color.Transparent;
                        }
                        
                        this.pbObjSelected = _pb;
                        this.pbObjSelected.BackColor = Color.Red;
                        updateGraphic();
                        return;
                    }
                }
            }

            
        }

        private void btnCreate_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Title = "Chọn ảnh map";
            ofd.Filter = "Image files (*.jpg, *.jpeg, *.jpe, *.jfif, *.png) | *.jpg; *.jpeg; *.jpe; *.jfif; *.png";
            ofd.InitialDirectory = @"C:\Users\dell\Desktop\";
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                String fileName = ofd.FileName;
                Bitmap background = new Bitmap(fileName);
                this.width_map = background.Width;
                this.height_map = background.Height;
                this.bmp_map = new Bitmap(background);
                int count_horizontal = this.width_map / 16;
                int count_vertical = this.height_map / 16;

                picMap.SizeMode = PictureBoxSizeMode.AutoSize;
                using(Graphics g = Graphics.FromImage(background))
                {
                    for( int row = 0; row < count_vertical; row++)
                    {
                        for( int col =0; col < count_horizontal; col++)
                        {
                            g.DrawLine(Pens.Red, new Point(col * 16, 0), new Point(col * 16, this.height_map));
                        }

                        g.DrawLine(Pens.Red, new Point(0, row * 16), new Point(this.width_map, row * 16));
                    }
                }

                picMap.Image = background;
                this.matrix = Utils.convertBitmap(background);
                context.create(this.bmp_map);
            }
        }

        private void btnOpen_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Title = "Chọn ảnh map";
            ofd.Filter = "Image files (*.jpg, *.jpeg, *.jpe, *.jfif, *.png) | *.jpg; *.jpeg; *.jpe; *.jfif; *.png";
            ofd.InitialDirectory = @"C:\Users\dell\Desktop\";
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                MyLogger.getInstance().logDebug("Open map ------------------------------------------");
                String fileName = ofd.FileName.Split('.')[0];
                Bitmap background = context.open(fileName);
                background.MakeTransparent(Color.FromArgb(255, 0, 255));
                this.width_map = background.Width;
                this.height_map = background.Height;
                this.bmp_map = new Bitmap(background);
                int count_horizontal = this.width_map / 16;
                int count_vertical = this.height_map / 16;

                this.bmp_map = new Bitmap(background);

                Bitmap _bmp = CreateMapSquare(background);

                using (Graphics g = Graphics.FromImage(_bmp))
                {
                    for (int row = 0; row < count_vertical; row++)
                    {
                        for (int col = 0; col < count_horizontal; col++)
                        {
                            g.DrawLine(Pens.Red, new Point(col * 16, 0), new Point(col * 16, this.height_map));
                        }

                        g.DrawLine(Pens.Red, new Point(0, row * 16), new Point(this.width_map, row * 16));
                    }
                }

                picMap.SizeMode = PictureBoxSizeMode.AutoSize;
                picMap.Image = _bmp;
                background = _bmp;

                RecObject recobj = new RecObject();
                recobj.parse(fileName+"recs.txt");
                this.recs.AddRange(recobj.Recs);

                EnemyObj enemyObj = new EnemyObj();
                enemyObj.parse(fileName + "enemy.txt");
                this.enemies.AddRange(enemyObj.Enemies);

                foreach (ObjGame obj in enemyObj.Enemies)
                {
                    ObjDTO objDTO = new ObjDTO(obj, folderDefault + "enemy/" + obj.Name + ".png");
                    pushObjGame(obj.X, obj.Y, objDTO);
                }
            }
        }

        private Bitmap CreateMapSquare(Bitmap background)
        {
            int size = Math.Max(background.Size.Width, background.Size.Height);
            Bitmap _bmp = new Bitmap(size, size);
            for (int y = 0; y < size; y++)
            {
                for (int x = 0; x < size; x++)
                {
                    _bmp.SetPixel(x, y, Color.Black);
                }
            }
            using (Graphics g = Graphics.FromImage(_bmp))
            {
                g.DrawImage(background, new Point(0, 0));
            }

            return _bmp;
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            //Bitmap bmp = Utils.convertMatrixToBitmap(this.matrix,this.width_map, this.height_map);
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Title = "Chọn ảnh map";
            sfd.Filter = "Image files (*.jpg, *.jpeg, *.jpe, *.jfif, *.png) | *.jpg; *.jpeg; *.jpe; *.jfif; *.png";
            sfd.InitialDirectory = @"C:\Users\dell\Desktop\";
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                String name = sfd.FileName.Split('.')[0];
                context.save(name);
                using (StreamWriter writer = new StreamWriter(name + "recs.txt"))
                {
                    foreach (Rectangle rec in this.recs)
                    {
                        Rec rectg = Rec.create(rec.X, rec.Y, rec.Width, rec.Height);
                        writer.WriteLine(rectg.intro());
                    }

                    writer.Close();
                }

                //using (StreamWriter writer = new StreamWriter(name + "quadtree.txt"))
                //{

                //    foreach (QNode node in this.nodes)
                //    {
                //        foreach(String str in node.toString())
                //        {
                //            writer.WriteLine(str);
                //        }
                //    }

                //    writer.Close();
                //}

                using (StreamWriter writer = new StreamWriter(name+"grid.txt"))
                {
                    foreach(var obj in this.cells)
                    {
                        foreach(var str in obj.toStringToList())
                        {
                            writer.WriteLine(str);
                        }
                    }

                    writer.Close();
                }

                using (StreamWriter writer = new StreamWriter(name + "bosses.txt"))
                {
                    foreach (ObjGame obj in this.bosses)
                    {
                        writer.WriteLine(obj.intro());
                    }

                    writer.Close();
                }

                using (StreamWriter writer = new StreamWriter(name + "enemy.txt"))
                {
                    foreach (ObjGame obj in this.enemies)
                    {
                        writer.WriteLine(obj.intro());
                    }

                    writer.Close();
                }

                using (StreamWriter writer = new StreamWriter(name + "item.txt"))
                {
                    foreach (Item item in this.itemList)
                    {
                        writer.WriteLine(item.intro());
                    }

                    writer.Close();
                }
            }
        }

        private void Home_Load(object sender, EventArgs e)
        {
            dataGridViewEnemy.RowTemplate.Height = 64;
            dataGridViewBoss.RowTemplate.Height = 64;
            dataGridViewItems.RowTemplate.Height = 64;
            
            importDataToDataGridView(dataGridViewEnemy, folderDefault + "enemy");
            importDataToDataGridView(dataGridViewItems, folderDefault + "items");
            importDataToDataGridView(dataGridViewBoss, folderDefault + "boss");

            setObject(null);
        }

        private void setObject(ObjGame obj)
        {
            this.txtX.Text = (obj != null)? obj.X.ToString() : "0";
            this.txtY.Text = (obj != null) ? obj.Y.ToString() : "0";
            this.txtVx.Text = (obj != null) ? obj.Width.ToString() : "0";
            this.txtVy.Text = (obj != null) ? obj.Height.ToString() : "0";
            this.txtType.Text = (obj != null) ? obj.Type.ToString() : "nothing";
            this.txtName.Text = (obj != null) ? obj.Name.ToString() : "nothing";
        }

        private void btnImportObj_Click(object sender, EventArgs e)
        {
            dataGridViewEnemy.Rows.Clear();
            dataGridViewEnemy.Refresh();
            importData(dataGridViewEnemy);
        }

        private void btnImportItems_Click(object sender, EventArgs e)
        {
            dataGridViewItems.Rows.Clear();
            dataGridViewItems.Refresh();
            importData(dataGridViewItems);
        }

        private void btnImportBoss_Click(object sender, EventArgs e)
        {
            dataGridViewBoss.Rows.Clear();
            dataGridViewBoss.Refresh();
            importData(dataGridViewBoss);
        }

        private void importData(DataGridView view)
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            fbd.SelectedPath = @"C:\Users\dell\Desktop\";
            if (fbd.ShowDialog() == DialogResult.OK)
            {
                String folderName = fbd.SelectedPath;

                importDataToDataGridView(view, folderName);
            }
        }

        private void importDataToDataGridView(DataGridView view,String pathName)
        {
            String folderName = pathName;
            DirectoryInfo Folder;
            FileInfo[] Images;

            Folder = new DirectoryInfo(folderName);
            Images = Folder.GetFiles();
            List<String> imagesList = new List<String>();

            for (int i = 0; i < Images.Length; i++)
            {

                String path = String.Format(@"{0}/{1}", folderName, Images[i].Name);

                if (path.IndexOf(".txt") == -1)
                {
                    var index = view.Rows.Add();
                    if(view == dataGridViewEnemy)
                    {
                        Bitmap _bmp = Utils.CreatBitmapTransparent(path);
                        enemiesPath.Add(path);
                        view.Rows[index].Cells["Enemy"].Value = _bmp;
                    }else if(view == dataGridViewBoss){
                        Bitmap _bmp = Utils.CreatBitmapTransparent(path);
                        view.Rows[index].Cells["boss"].Value = _bmp;
                        bossesPath.Add(path);
                    }else if(view == dataGridViewItems)
                    {
                        Bitmap _bmp = Utils.CreatBitmapTransparent(path);
                        itemsPath.Add(path);
                        view.Rows[index].Cells["items"].Value = _bmp;
                    }
                    
                }
            }
        }

        private void dataGridViewEnemy_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            int index = e.RowIndex;

            if (index < enemiesPath.Count)
            {
                var v = enemiesPath[e.RowIndex];
                ObjGame obj = new Enemy(v);
                setObject(obj);
                selectedObj = new ObjDTO(obj, v);
            }
        }

        private void dataGridViewItems_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            int index = e.RowIndex;
            if (index < itemsPath.Count)
            {
                var v = itemsPath[e.RowIndex];
                Item obj = new Item(v, txtContainer.Text);
                obj.Container = txtContainer.Text;
                setObject(obj);
                selectedObj = new ObjDTO(obj, v);
            }
        }

        private void dataGridViewBoss_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            var v = bossesPath[e.RowIndex];
            ObjGame obj = new Boss(v);
            setObject(obj);
            selectedObj = new ObjDTO(obj, v);
        }

        private void picMap_Paint(object sender, PaintEventArgs e)
        {
            using (Pen pen = new Pen(Color.Blue, 2))
            {
                foreach (Rectangle rec in this.recs)
                {
                    e.Graphics.DrawRectangle(pen, rec);
                }

                //foreach (ObjGame boss in this.bosses)
                //{
                //    Bitmap _bmp = Utils.CreatBitmapTransparent("../../images/boss/" + boss.Name + ".png");
                //    e.Graphics.DrawImage(_bmp, boss.X, boss.Y);
                //}

                //foreach (ObjGame enemy in this.enemies) {
                //    Bitmap _bmp = Utils.CreatBitmapTransparent("../../images/enemy/" + enemy.Name + ".png");
                //    e.Graphics.DrawImage(_bmp, enemy.X, enemy.Y);
                //}

                //foreach (ObjGame item in this.itemList)
                //{
                //    Bitmap _bmp = Utils.CreatBitmapTransparent("../../images/items/" + item.Name + ".png");
                //    e.Graphics.DrawImage(_bmp, item.X, item.Y);
                //}
            }

            // Draw quad tree
            using (Pen pen = new Pen(Color.Green, 2))
            {
                if (this.rectanglesOfQuadtree.Count > 0)
                {
                    foreach (Rectangle rec in this.rectanglesOfQuadtree)
                    {
                        e.Graphics.DrawRectangle(pen ,rec);
                    }
                }
            }

            e.Dispose();
        }

        private void btnBuildQuadtree_Click(object sender, EventArgs e)
        {
            List<ObjGame> _objGames = new List<ObjGame>();
            _objGames.AddRange(this.enemies);
            _objGames.AddRange(this.bosses);
            _objGames.AddRange(this.itemList);

            QNode root = new QNode("1", 0, 0, 0, picMap.Image.Width, picMap.Image.Height, _objGames);

            this.rectanglesOfQuadtree = Utils.converListQRegionToRectangle(root.getRegionOfQuadTree());
            this.nodes = root.getQNodeLeafOfQuadTree();
            updateGraphic();
        }

        private void updateGraphic()
        {
            this.Invalidate();
            this.Update();
            this.Refresh();
        }

        private void btnUpdateObject_Click(object sender, EventArgs e)
        {
            int _x = int.Parse(txtX.Text);
            int _y = int.Parse(txtY.Text);

            this.objGameSelected.X = _x;
            this.objGameSelected.Y = _y;
            this.pbObjSelected.Location = new Point(_x, _y);

            updateGraphic();
        }

        private void btnBuildGrid_Click(object sender, EventArgs e)
        {
            // validate input 
            try
            {
                int widthMap = this.width_map;
                int heightMap = this.height_map;
                int widthCell = int.Parse(txtWidthCell.Text);
                int heightCell = int.Parse(txtHeightCell.Text);

                

                List<ObjGame> _objGames = new List<ObjGame>();
                _objGames.AddRange(this.enemies);
                _objGames.AddRange(this.bosses);
                _objGames.AddRange(this.itemList);

                Grid grid = new Grid(widthMap, heightMap, widthCell, heightCell, _objGames);

                this.rectanglesOfQuadtree = Utils.convertListCellToRectangle(grid.Cells);
                this.cells = grid.Cells;
                updateGraphic();

                // set UI
                lblWidthMap.Text = widthMap.ToString();
                lblHeightMap.Text = heightMap.ToString();
                lblRow.Text = grid.Row.ToString();
                lblColumn.Text = grid.Col.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Division is not available");
            }
            
        }
    }
}
