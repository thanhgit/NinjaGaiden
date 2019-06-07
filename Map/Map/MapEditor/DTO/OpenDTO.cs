using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor.DTO
{
    public class OpenDTO
    {
        private int[,] matrix;
        private int col_map;
        private int row_map;

        public int[,] Matrix
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

        public int Col_map
        {
            get
            {
                return col_map;
            }

            set
            {
                col_map = value;
            }
        }

        public int Row_map
        {
            get
            {
                return row_map;
            }

            set
            {
                row_map = value;
            }
        }

        private OpenDTO(int[,] matrix, int col_map, int row_map)
        {
            this.Matrix = matrix;
            this.Col_map = col_map;
            this.Row_map = row_map;
        }

        public static OpenDTO create(int[,] matrix, int col_map,int row_map)
        {
            return new OpenDTO(matrix, col_map, row_map);
        }
    }
}
