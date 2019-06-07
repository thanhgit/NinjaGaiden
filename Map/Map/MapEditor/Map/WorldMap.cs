using Map.MapEditor.Map;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.MapEditor
{
    public class WorldMap
    {
        private int width_map;
        private int height_map;
        private int width_cell = 16;
        private int height_cell = 16;
        private int count_horizontal;
        private int count_vertical;
        private Tile[,] tiles;
        private List<Tile> children = new List<Tile>();
        private MapMatrix mapMatrix;
        private int[,] matrix_save;

      
        public int Width_map
        {
            get
            {
                return width_map;
            }

            set
            {
                width_map = value;
            }
        }

        public int Height_map
        {
            get
            {
                return height_map;
            }

            set
            {
                height_map = value;
            }
        }

        public List<Tile> Children
        {
            get
            {
                return children;
            }

            set
            {
                children = value;
            }
        }

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

        public int[,] Matrix_save
        {
            get
            {
                return matrix_save;
            }

            set
            {
                matrix_save = value;
            }
        }

        public MapMatrix MapMatrix
        {
            get
            {
                return mapMatrix;
            }

            set
            {
                mapMatrix = value;
            }
        }

        private WorldMap(ColorPixel[,] matrix, int width_map, int height_map)
        {
            this.width_map = width_map;
            this.height_map = height_map;
            this.count_horizontal = this.width_map / this.width_cell;
            this.count_vertical = this.height_map / this.height_cell;
            this.Matrix_save = new int[this.count_vertical, this.count_horizontal];
            this.MapMatrix = MapMatrix.create(this.count_vertical, this.count_horizontal, matrix);
            this.tiles = MapMatrix.create(this.count_vertical, this.count_horizontal, matrix).Tiles;
        }

        public static WorldMap create(ColorPixel[,] matrix,int width_map, int height_map)
        {
            return new WorldMap(matrix,width_map,height_map);
        }

        public static WorldMap restore(int[,] map, List<Tile> list, int col,int row)
        {
            ColorPixel[,] matrix = new ColorPixel[row*16, col*16];

            for(int r =0; r < row; r++)
            {
                for(int c =0; c < col; c++)
                {
                    int value = map[r, c];
                    Tile tile = list[map[r, c]];
                    for(int height = 0; height < 16; height++)
                    {
                        for(int width = 0; width < 16; width++)
                        {
                            matrix[r * 16 + height, c * 16 + width] = tile.Matrix[height, width];
                        }
                    }
                }
            }

            return new WorldMap(matrix, col*16, row*16);
        }

     

        public void createTiles()
        {
            for(int r = 0; r < this.count_vertical; r++)
            {
                for(int c = 0; c < this.count_horizontal; c++)
                {
                    int index = -1;
                    if ( (index = compare1N(this.tiles[r, c])) == -1)
                    {
                        this.Children.Add(this.tiles[r, c]);
                        this.Matrix_save[r, c] = this.children.IndexOf(this.tiles[r, c]);
                    }else
                    {
                        this.Matrix_save[r, c] = index;
                    }
                  
                }
            }
        }

        private int compare1N(Tile other)
        {
            int result = 0;

            if(this.Children.Count == 0)
            {
                return -1;
            }

            foreach(Tile tile in this.Children){
                if (tile.compare(other))
                {
                    return this.children.IndexOf(tile);
                }else
                {
                    result = -1;
                }
            }

            return result;
        }
    }
}
