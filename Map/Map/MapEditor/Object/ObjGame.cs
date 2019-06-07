using Map.MapEditor.FileSys.Object;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.Object
{
    public abstract class ObjGame
    {
        protected ObjDefault objDefault;
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

        public ObjGame(int x, int y, int width, int height, string type, string name)
        {
            this.x = x;
            this.y = y;
            this.width = width;
            this.height = height;
            this.Type = type;
            this.Name = name;
        }

        public ObjGame()
        {

        }

        public ObjGame(ObjGame other)
        {
            this.x = other.x;
            this.y = other.y;
            this.width = other.width;
            this.height = other.height;
            this.type = other.type;
            this.name = other.name;
        }

        public String toString()
        {
            return this.X + " " + this.Y + " " + this.Width + " " + this.Height + " " + this.Type + " " + this.Name;
        }
       
        public abstract String intro();
    }
}
