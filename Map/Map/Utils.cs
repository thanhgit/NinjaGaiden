using Map.MapEditor;
using Map.MapEditor.Map;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.MapEditor.Quadtree;

namespace Map
{
    public static class Utils
    {

        public static byte[] ToByteArray(Image image, ImageFormat format)
        {
            using (MemoryStream ms = new MemoryStream())
            {
                image.Save(ms, format);
                return ms.ToArray();
            }
        }

        public static  int[,] convertBitmap(Bitmap bmp)
        {
            int width = bmp.Width;
            int height = bmp.Height;
            int[,] result = new int[height, width];

            for(int row = 0; row < height; row++)
            {
                for(int col = 0; col < width; col++)
                {
                    result[row,col] = bmp.GetPixel(col, row).ToArgb();
                }
            }
            //UtilsFile.exportFile(@"C:\Users\dell\Desktop\l.txt", result, width, height);
            return result;
        }

        public static ColorPixel[,] convertBitmapToColorPixel(Bitmap bmp)
        {
            int width = bmp.Width;
            int height = bmp.Height;
            ColorPixel[,] result = new ColorPixel[height, width];

            for (int row = 0; row < height; row++)
            {
                for (int col = 0; col < width; col++)
                {
                    int value = bmp.GetPixel(col, row).ToArgb();
                    result[row, col] = ColorPixel.create(bmp.GetPixel(col, row).ToArgb());
                }
            }

            //UtilsFile.exportFileWithColorPixel(@"C:\Users\dell\Desktop\colorpixel.txt", result, width, height);

            return result;
        }

        public static int[,] convertFile(StreamReader reader, int width, int height)
        {
            int[,] result = new int[height, width];
            String line;
            int row = 0;
            while((line = reader.ReadLine()) != null)
            {
                String[] elements = line.Split(' ');
                for(int col = 0; col < width; col++)
                {
                    result[row, col] = Int16.Parse(elements[col]);
                }

                row++;
            }

            reader.Close();
            return result;
        }

        public static Bitmap convertMatrixToBitmap(int[,] matrix,int width, int height)
        {
            Bitmap result = new Bitmap(width, height);
            for(int row = 0; row < height; row++)
            {
                for(int col = 0; col < width; col++)
                {
                    result.SetPixel(col, row, Color.FromArgb(matrix[row, col]));
                }
            }

            return result;
        }

        public static Bitmap convertTilesToBitmap(Tile[,] tiles, int row, int col)
        {
            Bitmap result = new Bitmap(col*16, row*16);
            for (int r = 0; r < row; r++)
            {
                for (int c = 0; c < col; c++)
                {
                    Tile tile = tiles[r,c];
                    Bitmap tmp = Utils.convertMatrixColorPixelToBitmap(tile.Matrix, 16, 16);
                    using (Graphics g = Graphics.FromImage(result))
                    {
                        g.DrawImage(tmp, new Point(c * 16, r * 16));
                    }
                }
            }

            return result;
        }

        public static Bitmap convertMatrixColorPixelToBitmap(ColorPixel[,] matrix, int width, int height)
        {
            Bitmap result = new Bitmap(width, height);
            for (int row = 0; row < height; row++)
            {
                for (int col = 0; col < width; col++)
                {
                    result.SetPixel(col, row, Color.FromArgb(matrix[row, col].Identified));
                }
            }

            return result;
        }

        public static Bitmap CreatBitmapTransparent(String path)
        {
            if (path == null || path.Equals(""))
            {
                return null;
            } else
            {
                Bitmap _bmp = new Bitmap(path);
                _bmp.MakeTransparent(Color.FromArgb(255, 0, 255));
                return _bmp;
            }
            
        }

        public static Rectangle convertQRegionToRectangle(QRegion qRegion)
        {
            return new Rectangle(qRegion.X, qRegion.Y, qRegion.Width, qRegion.Height);
        }

        public static List<Rectangle> converListQRegionToRectangle(List<QRegion> qRegions)
        {
            List<Rectangle> results = new List<Rectangle>();
            foreach (QRegion qRegion in qRegions)
            {
                results.Add(convertQRegionToRectangle(qRegion));
            }

            return results;
        }

    }
}
