using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.FileSys.Object
{
    public abstract class ObjDefault
    {
        private int x, y;
        private int width, height;
        private String type;
        private String name;

        #region
        public int X
        {
            get
            {
                return x;
            }

            set
            {
                x = value;
            }
        }

        public int Y
        {
            get
            {
                return y;
            }

            set
            {
                y = value;
            }
        }

        public string Type
        {
            get
            {
                return type;
            }

            set
            {
                type = value;
            }
        }

        public string Name
        {
            get
            {
                return name;
            }

            set
            {
                name = value;
            }
        }

        public int Width
        {
            get
            {
                return width;
            }

            set
            {
                width = value;
            }
        }

        public int Height
        {
            get
            {
                return height;
            }

            set
            {
                height = value;
            }
        }

        #endregion

        public ObjDefault(int x, int y, int width, int height, string type, string name)
        {
            this.x = x;
            this.y = y;
            this.width = width;
            this.height = height;
            this.Type = type;
            this.Name = name;
        }

        public ObjDefault()
        {

        }

        public abstract void parse(String fileName);

    }
}
