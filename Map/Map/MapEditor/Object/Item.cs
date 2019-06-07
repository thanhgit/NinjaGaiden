using Map.MapEditor.FileSys.Object;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.Object
{
    public class Item : ObjGame
    {
        String container;

        public string Container
        {
            get
            {
                return container;
            }

            set
            {
                container = value;
            }
        }

        public Item(int x, int y, int width, int height, string type, string name,string container) : base(x, y, width, height, type, name)
        {
            this.Container = container;
        }

        public Item(String fileName)
        {
            ItemDefault itemDefault = (ItemDefault)objDefault;
            itemDefault = new ItemObj();
            itemDefault.parse(fileName);
            this.X = itemDefault.X;
            this.Y = itemDefault.Y;
            this.Width = itemDefault.Width;
            this.Height = itemDefault.Height;
            this.Type = itemDefault.Type;
            this.Name = itemDefault.Name;
            this.Container = itemDefault.Container;
        }

        public Item(String fileName,String container)
        {
            ItemDefault itemDefault = (ItemDefault)objDefault;
            itemDefault = new ItemObj();
            itemDefault.parse(fileName);
            this.X = itemDefault.X;
            this.Y = itemDefault.Y;
            this.Width = itemDefault.Width;
            this.Height = itemDefault.Height;
            this.Type = itemDefault.Type;
            this.Name = itemDefault.Name;
            this.Container = container;
        }

        public Item(ObjGame obj) : base(obj)
        {

        }

        public Item(ObjGame obj,String container) : base(obj)
        {
            this.container = container;
        }

        public override string intro()
        {
            return this.X + " " + this.Y + " " + this.Width + " " + this.Height + " " + this.Type + " " + this.Name + " " + this.Container;
        }
    }
}
