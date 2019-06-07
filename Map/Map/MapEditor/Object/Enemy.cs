using Map.MapEditor.FileSys.Object;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.Object
{
    public class Enemy : ObjGame
    {
        public Enemy(int x, int y, int width, int height, string type, string name) : base(x, y, width, height, type, name)
        {
        }

        public Enemy(String fileName)
        {
            objDefault = new EnemyObj();
            objDefault.parse(fileName);
            this.X = objDefault.X;
            this.Y = objDefault.Y;
            this.Width = objDefault.Width;
            this.Height = objDefault.Height;
            this.Type = objDefault.Type;
            this.Name = objDefault.Name;
        }

        public Enemy(ObjGame obj) : base(obj)
        {

        }

        public override string intro()
        {
            return this.X + " " + this.Y + " " + this.Width + " " + this.Height + " " + this.Type + " " + this.Name;
        }
    }
}
