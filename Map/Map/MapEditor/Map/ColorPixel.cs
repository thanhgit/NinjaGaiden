using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor
{
    public class ColorPixel
    {
        private int red;
        private int green;
        private int blue;
        private int identified;

        #region Get_Set
        public int Red
        {
            get
            {
                return red;
            }

            set
            {
                red = value;
            }
        }

        public int Green
        {
            get
            {
                return green;
            }

            set
            {
                green = value;
            }
        }

        public int Blue
        {
            get
            {
                return blue;
            }

            set
            {
                blue = value;
            }
        }

        public int Identified
        {
            get
            {
                return identified;
            }

            set
            {
                identified = value;
            }
        }
        #endregion

        private ColorPixel(int red, int green, int blue)
        {
            this.red = red;
            this.green = green;
            this.blue = blue;
            this.identified = (this.Red + 1) * (this.Green + 1) * (this.Blue + 1);
        }

        private ColorPixel(int value)
        {
            this.identified = value;
        }

        public static ColorPixel RGB(int red, int green, int blue)
        {
            return new ColorPixel(red, green, blue);
        }

        public static ColorPixel create(int value)
        {
            return new ColorPixel(value);
        }

        public bool compare(ColorPixel obj1)
        {
            ColorPixel p1 = this;
            ColorPixel p2 = obj1;
            bool result = false;
            if(p1.Identified == p2.Identified)
            {
                result = true;
            }

            return result;
        }

        
    }
}
