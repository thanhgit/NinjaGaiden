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
    public class LadderObj: ObjDefault
    {
        private List<Ladder> ladders = new List<Ladder>();

        public List<Ladder> Ladders
        {
            get
            {
                return ladders;
            }

            set
            {
                ladders = value;
            }
        }

        public override void parse(string fileName)
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
                        Ladder Ladder = new Ladder(x, y, width, height, type, name);
                        this.Ladders.Add(Ladder);
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
                this.Type = "Ladder";
                this.Name = nameObj;
            }
        }
    }
}

