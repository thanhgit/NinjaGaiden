using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.MapEditor.Quadtree;
using Map.MapEditor.Object;
using Map.MapEditor.Grid;

namespace TestApp
{
    public class Program
    {
        static void QuadtreeTest()
        {
            List<ObjGame> objs = new List<ObjGame>();
            objs.Add(new Enemy(134, 75, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(332, 78, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(558, 63, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(689, 55, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(781, 81, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(722, 157, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(557, 139, 25, 43, "enemy", "banshee"));
            QNode root = new QNode("1", 0, 0, 0, 2050, 2050, objs);
            System.Console.WriteLine("-----------Get all node-------------");
            List<QRegion> regions = root.getRegionOfQuadTree();
            foreach (QRegion region in regions)
            {
                foreach (String str in region.toString())
                {
                    System.Console.WriteLine(str);
                }
            }
            System.Console.WriteLine("Count: " + regions.Count);

            System.Console.WriteLine("-----------Get leaf node-------------");
            List<QNode> nodes = root.getQNodeLeafOfQuadTree();
            foreach (QNode node in nodes)
            {
                foreach (String str in node.Region.toString())
                {
                    System.Console.WriteLine(str);
                }
            }
            System.Console.WriteLine("Count: " + nodes.Count);
        }

        static void GridTest()
        {
            List<ObjGame> objs = new List<ObjGame>();
            objs.Add(new Enemy(134, 75, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(332, 78, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(558, 63, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(689, 55, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(781, 81, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(722, 157, 25, 43, "enemy", "banshee"));
            objs.Add(new Enemy(557, 139, 25, 43, "enemy", "banshee"));
            Grid grid = new Grid(2048, 208, 256, 208, objs);
            foreach (var obj in grid.Cells)
            {
                System.Console.WriteLine(obj.toString());
            }

        }
        static void Main(string[] args)
        {
            System.Console.WriteLine("---------------------------Test------------------------");
            //QuadtreeTest();
            GridTest();
            System.Console.ReadKey();
        }
    }
}
