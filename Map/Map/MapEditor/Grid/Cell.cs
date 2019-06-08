using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.MapEditor.Object;

namespace Map.MapEditor.Grid
{
    public class Cell
    {
        private string cellId;
        private int x, y;
        private int width, height;
        private List<ObjGame> objs;

        public Cell(string cellId,int x, int y, int width, int height, List<ObjGame> objs)
        {
            this.cellId = cellId;
            this.x = x;
            this.y = y;
            this.width = width;
            this.height = height;
            this.objs = new List<ObjGame>();
            this.objs.AddRange(objs);
        }

        public static bool IsContain(ObjGame obj, int x, int y, int width, int height)
        {
            bool result = false;

            bool check_x = obj.X >= x && obj.X < (x + width);
            bool check_y = obj.Y >= y && obj.Y < (y + height);

            if (check_x && check_y)
            {
                result = true;
            }

            return result;
        }

        public static List<ObjGame> CellContain(List<ObjGame> objs, int x, int y, int width, int height)
        {
            List<ObjGame> results = new List<ObjGame>();
            foreach(var obj in objs)
            {
                if (IsContain(obj, x, y, width, height))
                {
                    results.Add(obj);
                }
            }

            return results;
        }

        #region Get Set
        public string CellId
        {
            get
            {
                return this.cellId;
            }

            set
            {
                this.cellId = value; 
            }
        }

        public int X
        {
            get
            {
                return this.x;
            }

            set
            {
                this.x = value;
            }
        }

        public int Y
        {
            get
            {
                return this.y;
            }

            set
            {
                this.y = value;
            }
        }

        public int Width
        {
            get
            {
                return this.width;
            }

            set
            {
                this.width = value;
            }
        }

        public int Height
        {
            get
            {
                return this.height;
            }

            set
            {
                this.height = value;
            }
        }

        public List<ObjGame> Objs
        {
            get
            {
                return this.objs;
            }

            set
            {
                this.objs.Clear();
                this.objs.AddRange(value);
            }
        }
        #endregion

        public string toString()
        {
            String result = "";
            result += this.cellId + "\n";
            result += this.x + " " + this.y + " " + this.width + " " + this.height;
            foreach (var obj in this.objs)
            {
                result += "\n" + obj.intro();
            }
            return result;
        }

        public List<String> toStringToList()
        {
            List<String> results = new List<string>();
            results.Add(this.cellId);
            results.Add(this.x + " " + this.y + " " + this.width + " " + this.height);
            foreach (var obj in this.objs)
            {
                results.Add(obj.intro());
            }

            return results;
        }
    }
}
