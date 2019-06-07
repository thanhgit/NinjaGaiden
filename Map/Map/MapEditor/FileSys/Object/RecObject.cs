using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.FileSys.Object
{
    public class RecObject : ObjDefault
    {
        private List<Rectangle> recs = new List<Rectangle>();

        public List<Rectangle> Recs
        {
            get
            {
                return recs;
            }

            set
            {
                recs = value;
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
                            Rectangle rec = new Rectangle(x, y, width, height);
                            this.Recs.Add(rec);
                        }
                    }
                }
            } catch (Exception ex)
            {

            }
        }
    }
}
