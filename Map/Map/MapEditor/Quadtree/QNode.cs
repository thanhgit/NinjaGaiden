using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.MapEditor.Object;

namespace Map.MapEditor.Quadtree
{
    public class QNode
    {
        private QNode node1;
        private QNode node2;
        private QNode node3;
        private QNode node4;

        private String nodeId;
        private int level;

        private QRegion region;

        public QNode(String nodeId,int level, int x, int y, int width, int height, List<ObjGame> objs)
        {
            this.NodeId = nodeId;
            this.Level = level;
            this.Region = new QRegion(x, y, width, height);
            this.Region.Objs = objs;

            if (this.Region.IsSplit())
            {
                split();
            }
        }

        public void addObjGame(ObjGame obj)
        {
            this.Region.AddObj(obj);

            if (this.Region.IsSplit())
            {
                split();
            }
        }

        public void split()
        {
            this.Node1 = null;
            this.Node2 = null;
            this.Node3 = null;
            this.Node4 = null;

            List<ObjGame> objNode1 = new List<ObjGame>();
            List<ObjGame> objNode2 = new List<ObjGame>();
            List<ObjGame> objNode3 = new List<ObjGame>();
            List<ObjGame> objNode4 = new List<ObjGame>();
            foreach (ObjGame obj in this.Region.Objs)
            {
                switch(region.getNumberNodeWhenSplit(obj))
                {
                    case QRegion.QUADTREE_NODE.NODE1:
                        objNode1.Add(obj);
                        break;
                    case QRegion.QUADTREE_NODE.NODE2:
                        objNode2.Add(obj);
                        break;
                    case QRegion.QUADTREE_NODE.NODE3:
                        objNode3.Add(obj);
                        break;
                    case QRegion.QUADTREE_NODE.NODE4:
                        objNode4.Add(obj);
                        break;
                }
            }

            if (objNode1.Count > 0)
            {
                this.Node1 = new QNode(this.NodeId+"1", this.Level+1, this.Region.X, this.Region.Y, this.Region.Width/2, this.Region.Height/2, objNode1);
            }

            if (objNode2.Count > 0)
            {
                this.Node2 = new QNode(this.NodeId + "2", this.Level + 1, this.Region.X + this.Region.Width/2, this.Region.Y, this.Region.Width / 2, this.Region.Height / 2, objNode2);
            }

            if (objNode3.Count > 0)
            {
                this.Node3 = new QNode(this.NodeId + "3", this.Level + 1, this.Region.X, this.Region.Y + this.Region.Height/2, this.Region.Width / 2, this.Region.Height / 2, objNode3);

            }

            if (objNode4.Count > 0)
            {
                this.Node4 = new QNode(this.NodeId + "4", this.Level + 1, this.Region.X + this.Region.Width/2, this.Region.Y + this.Region.Height/2, this.Region.Width / 2, this.Region.Height / 2, objNode1);
            }
        }

        public int getLevel()
        {
            int result = this.Level;
            if (this.Node1 != null)
            {
                int _level = this.Node1.getLevel();
                if (_level > result)
                {
                    result = _level;
                }
            }

            if (this.Node2 != null)
            {
                int _level = this.Node2.getLevel();
                if (_level > result)
                {
                    result = _level;
                }
            }

            if (this.Node3 != null)
            {
                int _level = this.Node3.getLevel();
                if (_level > result)
                {
                    result = _level;
                }
            }

            if (this.Node4 != null)
            {
                int _level = this.Node4.getLevel();
                if (_level > result)
                {
                    result = _level;
                }
            }

            return result;
        }

        public void display()
        {
            System.Console.WriteLine("IdNode: "+this.NodeId+" , Number of Object "+this.Region.ObjsSize());
            if (this.Node1 != null)
            {
                this.Node1.display();
            }

            if (this.Node2 != null)
            {
                this.Node2.display();
            }

            if (this.Node3 != null)
            {
                this.Node3.display();
            }

            if (this.Node4 != null)
            {
                this.Node4.display();
            }
        }

        public void displayRegion()
        {
            System.Console.WriteLine(this.Region.toString());
            if (this.Node1 != null)
            {
                this.Node1.displayRegion();
            }

            if (this.Node2 != null)
            {
                this.Node2.displayRegion();
            }

            if (this.Node3 != null)
            {
                this.Node3.displayRegion();
            }

            if (this.Node4 != null)
            {
                this.Node4.displayRegion();
            }
        }

        public List<QRegion> getRegionOfQuadTree()
        {
            List<QRegion> regions = new List<QRegion>();
            regions.Add(this.Region);

            if (this.Node1 != null) 
            {
                regions.AddRange(this.Node1.getRegionOfQuadTree());
            }

            if (this.Node2 != null)
            {
                regions.AddRange(this.Node2.getRegionOfQuadTree());
            }

            if (this.Node3 != null)
            {
                regions.AddRange(this.Node3.getRegionOfQuadTree());
            }

            if (this.Node4 != null)
            {
                regions.AddRange(this.Node4.getRegionOfQuadTree());
            }

            return regions;
        }

        public List<QNode> getQNodeLeafOfQuadTree()
        {
            List<QNode> nodes = new List<QNode>();
            if ((this.Node1 == null &&
                this.Node2 == null &&
                this.Node3 == null &&
                this.Node4 == null))
            {
                nodes.Add(this);
            }

            if (this.Node1 != null)
            {
                nodes.AddRange(this.Node1.getQNodeLeafOfQuadTree());
            }

            if (this.Node2 != null)
            {
                nodes.AddRange(this.Node2.getQNodeLeafOfQuadTree());
            }

            if (this.Node3 != null)
            {
                nodes.AddRange(this.Node3.getQNodeLeafOfQuadTree());
            }

            if (this.Node4 != null)
            {
                nodes.AddRange(this.Node4.getQNodeLeafOfQuadTree());
            }

            return nodes;
        }

        public List<String> toString()
        {
            List<String> results = new List<string>();
            results.Add(this.NodeId + " " + this.Level);
            results.AddRange(this.Region.toString());
            return results;
        }
        #region Get Set
        public QNode Node1
        {
            get
            {
                return node1;
            }

            set
            {
                this.node1 = value;
            }
        }

        public QNode Node2
        {
            get
            {
                return this.node2;
            }

            set
            {
                this.node2 = value;
            }
        }

        public QNode Node3
        {
            get
            {
                return this.node3;
            }

            set
            {
                this.node3 = value;
            }
        }

        public QNode Node4
        {
            get
            {
                return this.node4;
            }

            set
            {
                this.node4 = value;
            }
        }

        public String NodeId
        {
            get
            {
                return this.nodeId;
            }

            set
            {
                this.nodeId = value;
            }
        }

        public int Level
        {
            get
            {
                return this.level;
            }

            set
            {
                this.level = value;
            }
        }

        public QRegion Region
        {
            get
            {
                return this.region;
            }

            set
            {
                this.region = value;
            }
        }
        #endregion
    }
}
