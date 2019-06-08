using Map.MapEditor;
using Map.MapEditor.DTO;
using Map.MapEditor.Map;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map
{
    public class HomeContext
    {
        private Home home;

        private ColorPixel[,] matrix_map;
        private int width_map;
        private int height_map;
        private int row_map;
        private int col_map;
        private int width_cell = 16;
        private int height_cell = 16;

        private WorldMap worldmap;

        public HomeContext(Home home)
        {
            this.home = home;
        }

        public void create(Bitmap bmp)
        {
            this.width_map = bmp.Width;
            this.height_map = bmp.Height;
            this.row_map = this.height_map / 16;
            this.col_map = this.width_map / 16;
            this.matrix_map = Utils.convertBitmapToColorPixel(bmp);
            worldmap = WorldMap.create(this.matrix_map, bmp.Width, bmp.Height);
            worldmap.createTiles();
        }

        public Bitmap open(String name)
        {
            OpenDTO open = UtilsFile.importFile(name + ".txt");
            int[,] matrix_map = open.Matrix;

            Bitmap tmp = new Bitmap(name + ".png");
            int width = tmp.Width;
            int height = tmp.Height;
            this.col_map = open.Col_map;
            this.row_map = open.Row_map;
            int col = width / 16;
            int row = height / 16;

            ColorPixel[,] mt = Utils.convertBitmapToColorPixel(tmp);
            WorldMap wm = WorldMap.create(mt, width, height);
            wm.createTiles();
            List<Tile> list = wm.Children;

            worldmap = WorldMap.restore(matrix_map, list, this.col_map, this.row_map);
            worldmap.createTiles();
            Tile[,] tiles = worldmap.Tiles;


            Bitmap rs = Utils.convertTilesToBitmap(tiles, this.row_map, this.col_map);
            return rs;
        }

        public void save(String name)
        {
            try
            {
                List<Tile> tiles = worldmap.Children;
                int count = worldmap.Children.Count;
                Bitmap bg = new Bitmap(count * 16, 16);

                using (Graphics g = Graphics.FromImage(bg))
                {
                    for (int c = 0; c < count; c++)
                    {
                        Bitmap tmp = Utils.convertMatrixColorPixelToBitmap(tiles[c].Matrix, 16, 16);
                        g.DrawImage(tmp, new Point(c * 16, 0));
                    }
                }

                UtilsFile.exportFile(name + ".txt", worldmap.Matrix_save, this.col_map, this.row_map);

                bg.Save(name + ".png");
                bg.Dispose();
            }
            catch (Exception ex)
            {

            }
            
        }
    }
}
