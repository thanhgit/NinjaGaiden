using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.MapEditor.Object;


namespace Map.MapEditor.Grid
{
    public class Grid
    {
        private int widthMap;
        private int heightMap;
        private int widthCell;
        private int heightCell;

        private int row, col;

        private List<Cell> cells;

        public Grid(int widthMap, int heightMap, int widthCell, int heightCell, List<ObjGame> objs)
        {
            this.widthMap = widthMap;
            this.heightMap = heightMap;
            this.widthCell = widthCell;
            this.heightCell = heightCell;
            this.cells = new List<Cell>();

            this.row = this.heightMap / this.heightCell;
            this.col = this.WidthMap / this.widthCell;

            if (this.heightMap % this.heightCell == 0 && this.WidthMap % this.widthCell == 0)
            {
                split(objs);
            } else
            {
                throw new Exception("Division is not available");
            }
        }

        public void split(List<ObjGame> objs)
        {
            for (int index_row = 0; index_row < this.row; index_row ++)
            {
                for (int index_col = 0; index_col < this.col; index_col++)
                {
                    String cellId = index_row + "," + index_col;
                    int x = (index_col * this.widthCell);
                    int y = (index_row * this.heightCell);
                    int width = this.widthCell;
                    int height = this.heightCell;
                    List<ObjGame> _obj = new List<ObjGame>();
                    _obj.AddRange(Cell.CellContain(objs, x, y, width, height));

                    Cell cell = new Cell(cellId, x, y, width, height, _obj);
                    this.cells.Add(cell);
                }
            }
        }

        #region Get Set 
        public int WidthMap
        {
            get
            {
                return this.widthMap;
            }

            set
            {
                this.widthMap = value;
            }
        }

        public int HeightMap
        {
            get
            {
                return this.heightMap;
            }

            set
            {
                this.heightMap = value;
            }
        }

        public int WidthCell
        {
            get
            {
                return this.widthCell;
            }

            set
            {
                this.widthCell = value;
            }
        }

        public int HeightCell
        {
            get
            {
                return this.heightCell;
            }

            set
            {
                this.heightCell = value;
            }
        }

        public int Row
        {
            get
            {
                return this.row;
            }

            set
            {
                this.row = value;
            }
        }

        public int Col
        {
            get
            {
                return this.col;
            }

            set
            {
                this.col = value;
            }
        }

        public List<Cell> Cells
        {
            get
            {
                return this.cells;
            }

            set
            {
                this.cells.Clear();
                this.cells.AddRange(value);
            }
        }
        #endregion
    }
}
