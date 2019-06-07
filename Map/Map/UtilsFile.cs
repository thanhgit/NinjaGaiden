using Map.MapEditor;
using Map.MapEditor.DTO;
using Map.MapEditor.Object;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map
{
    public static class UtilsFile
    {
        public static void exportFile(String name, int[,] matrix, int width, int height)
        {
            StreamWriter writer = new StreamWriter(name);
            writer.WriteLine(width + " " + height);
            for(int row = 0; row < height; row++)
            {
                String line = "";
                for(int col = 0; col < width; col++)
                {
                    line += matrix[row, col] + " ";
                }

                writer.WriteLine(line);
            }

            writer.Close();
        }

        public static void exportFileWithColorPixel(String name, ColorPixel[,] matrix, int width, int height)
        {
            StreamWriter writer = new StreamWriter(name);
            for (int row = 0; row < height; row++)
            {
                String line = "";
                for (int col = 0; col < width; col++)
                {
                    line += matrix[row, col].Identified + " ";
                }

                writer.WriteLine(line);
            }

            writer.Close();
        }

        public static OpenDTO importFile(String name)
        {
         
            int[,] result = null;
            StreamReader reader = new StreamReader(name);
            String line = reader.ReadLine();
            int width = int.Parse(line.Split(' ')[0]);
            int height = int.Parse(line.Split(' ')[1]);

            List<int[]> list = new List<int[]>();

            while((line = reader.ReadLine()) != null)
            {
                String[] values = line.Trim().Split(' ');
                

                int[] tmp = new int[width];
                for (int c = 0; c < width; c++)
                {
                    tmp[c] = int.Parse(values[c]);
                }

                list.Add(tmp);
            }

            result = new int[list.Count, width];
            for( int row =0; row < list.Count; row++)
            {
                for( int col = 0; col < width; col++)
                {
                    result[row, col] =list[row][col];
                }
            }

            return OpenDTO.create(result,width,height);
        }

    }
}
