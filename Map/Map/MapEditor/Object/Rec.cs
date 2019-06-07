using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.Object
{
    public class Rec : ObjGame
    {
        public Rec(int x, int y, int width, int height, string type, string name) : base(x, y, width, height, type, name)
        {
        }

        public static Rec create(int x,int y,int width,int height)
        {
            return new Rec(x, y, width, height, "rec", "rec");
        }

        public override string intro()
        {
            return this.X + " " + this.Y + " " + this.Width + " " + this.Height + " " + this.Type + " " + this.Name;
        }
    }
}
