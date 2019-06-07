using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.Map
{
    public class Tile
    {
        private int col;
        private int row;
        private int width=16;
        private int height=16;
        private ColorPixel[,] matrix;

        public ColorPixel[,] Matrix
        {
            get
            {
                return matrix;
            }

            set
            {
                matrix = value;
            }
        }

        private Tile(ColorPixel[,] matrix,int col, int row)
        {
            this.Matrix = matrix;
            this.col = col;
            this.row = row;
        }

        public static Tile create(ColorPixel[,] matrix, int col, int row)
        {
            return new Tile(matrix, col, row);
        }

        public bool compare(Tile other)
        {
            Tile p1 = this;
            Tile p2 = other;
            bool result = false;
           
            if ((p1.width != p2.width) || (p1.height != p2.height))
            {
                return false;
            } else if ( (!p1.Matrix[0, 0].compare(p2.Matrix[0, 0])) ||
                         (!p1.Matrix[0, this.width - 1].compare(p2.Matrix[0, this.width - 1])) ||
                         (!p1.Matrix[this.height - 1, 0].compare(p2.Matrix[this.height - 1, 0])) ||
                         (!p1.Matrix[this.height-1, this.width-1].compare(p2.Matrix[this.height-1, this.width-1])) ||
                         (!p1.Matrix[this.height/2, this.width/2].compare(p2.Matrix[this.height/2, this.width/2])))
            {
                return false;
            }
            else
            {
                for(int r = 0; r < this.height; r++)
                {
                    for(int c = 0; c < this.width; c++)
                    {
                        if(p1.Matrix[r,c].compare(p2.Matrix[r, c]))
                        {                       
                            result = true;
                        }else
                        {
                            return false;
                        }
                    }
                }
            }

            return result;
        }
    }
}
