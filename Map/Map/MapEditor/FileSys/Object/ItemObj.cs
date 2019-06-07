using Map.MapEditor.Object;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.FileSys.Object
{
    public class ItemObj : ItemDefault
    {
        private List<Item> items = new List<Item>();
        public List<Item> Items
        {
            get
            {
                return items;
            }

            set
            {
                items = value;
            }
        }

        public override void parse(string fileName)
        {
            try
            {
                if (fileName.Split('.')[1].Equals("txt"))
                {
                    using (StreamReader reader = new StreamReader(fileName))
                    {
                        String line = "";
                        while ((line = reader.ReadLine()) != null)
                        {
                            String[] words = line.Trim().Split(' ');
                            int x = int.Parse(words[0]);
                            int y = int.Parse(words[1]);
                            int width = int.Parse(words[2]);
                            int height = int.Parse(words[3]);
                            String type = words[4];
                            String name = words[5];
                            String container = words[6];
                            Item item = new Item(x, y, width, height, type, name, container);
                            this.items.Add(item);
                        }
                    }
                }
                else
                {
                    String nameObj = Path.GetFileName(fileName).Split('.')[0];
                    Bitmap bmp = new Bitmap(fileName);
                    this.X = 0;
                    this.Y = 0;
                    this.Width = bmp.Width;
                    this.Height = bmp.Height;
                    this.Type = "item";
                    this.Name = nameObj;
                    this.Container = "nothing";
                }
            }
            catch (Exception ex)
            {

            }
        }
    }
}
