using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.FileSys.Object
{
    public abstract class ItemDefault : ObjDefault
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

        public ItemDefault(int x, int y, int width, int height, string type, string name,string container):base( x,  y,  width,  height,  type,  name){
            this.Container = container;
        }

        public ItemDefault()
        {

        }
    }
}
