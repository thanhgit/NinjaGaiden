using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.MapEditor.Object;

namespace Map.MapEditor.Quadtree
{
    public class QRegion
    {
        public enum QUADTREE_NODE
        {
            NODE1,
            NODE2,
            NODE3,
            NODE4
        }

        private int x, y;
        private int width, height;
        private List<ObjGame> objs = new List<ObjGame>();

        public QRegion (int x, int y, int width, int height)
        {
            this.X = x;
            this.Y = y;
            this.Width = width;
            this.Height = height;
        }

        public void AddObj(ObjGame obj)
        {
            if (obj != null)
            {
                this.objs.Add(obj);
            }
            else
            {
                MyLogger.getInstance().logDebug("Add object in null");
            }
        }

        public void RemoveObj(ObjGame obj)
        {
            if (obj != null)
            {
                this.objs.Remove(obj);
            }
            else
            {
                MyLogger.getInstance().logDebug("Removed object is null");
            }
        }

        public int ObjsSize()
        {
            return this.objs.Count;
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

        public bool IsSplit()
        {
            if (objs.Count > 3)
            {
                return true;
            } else
            {
                return false;
            }
        }

        public QUADTREE_NODE getNumberNodeWhenSplit(ObjGame obj)
        {
            if (IsContain(obj, x, y, width/2, height/2))
            {
                return QUADTREE_NODE.NODE1;
            } else if (IsContain(obj, x + width/2, y, width/2, height/2))
            {
                return QUADTREE_NODE.NODE2;
            } else if (IsContain(obj, x, y + height/2, width/2, height/2))
            {
                return QUADTREE_NODE.NODE3;
            } else
            {
                return QUADTREE_NODE.NODE4;
            }
        }

        public List<String> toString()
        {
            List<String> results = new List<string>();
            results.Add(this.X + " " + this.Y + " " + this.Width + " " + this.Height);
            foreach (ObjGame obj in this.objs)
            {
                results.Add(obj.intro());
            }
            return results;
        }
        #region

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
                this.objs.AddRange(value);
            }
        }

        #endregion

        
    }
}
