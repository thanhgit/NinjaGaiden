using Map.MapEditor.Map;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor
{
    public class MapMatrix
    {
        private ColorPixel[,] matrix;
        private Tile[,] tiles;
        private int row;
        private int col;
        private int width_cell = 16;
        private int height_cell = 16;

        public Tile[,] Tiles
        {
            get
            {
                return tiles;
            }

            set
            {
                tiles = value;
            }
        }

        private MapMatrix(int row, int col, ColorPixel[,] matrix)
        {
            this.row = row;
            this.col = col;
            this.matrix = matrix;
            split();      
        }

        

        public static MapMatrix create(int row, int col, ColorPixel[,] matrix)
        {
            return new MapMatrix(row, col, matrix);
        }

        private void split()
        {
            tiles = new Tile[this.row,this.col];
            for (int r = 0; r < this.row; r++)
            {
                for (int c = 0; c < this.col; c++)
                {
                    tiles[r, c] = Tile.create(createMatrix(c * this.width_cell, r * this.height_cell), c, r);
                }
            }
        }

        private ColorPixel[,] createMatrix(int x, int y)
        {
            ColorPixel[,] result = new ColorPixel[this.height_cell, this.width_cell];

            for (int r = 0; r < this.height_cell; r++)
            {
                for (int c = 0; c < this.width_cell; c++)
                {
                    result[r, c] = ColorPixel.create(this.matrix[r + y, c + x].Identified);
                }
            }

            return result;
        }

    }
}
