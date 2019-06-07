using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.HomeControl
{
    public class InvokeMap
    {
        IHomeCommand command;

        public InvokeMap(IHomeCommand command)
        {
            this.command = command;
        }

        public void execute()
        {
            this.command.perform();
        }
    }
}
