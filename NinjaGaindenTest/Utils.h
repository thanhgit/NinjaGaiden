#ifndef UTILS_H
#define UTILS_H
class Utils
{
public:
	const static int WIDTH_SCREEN = 256;
	const static int HEIGHT_SCREEN = 208;

	const static int WORLMAP_WIDTH = 2050;
	const static int WORLMAP_HEIGHT = 208;

	const static int VIEWPORT_WIDTH_COL = 18;
	const static int VIEWPORT_HEIGHT_COL = 14;

	const static int CELL_WIDTH = 16;
	const static int CELL_HEIGHT = 16;

};

enum COLLISION_DIRECTION
{
	LEFT,
	UP,
	RIGHT,
	DOWN,
	NONE
};

enum QUADTREE_NODE
{
	NODE1,
	NODE2,
	NODE3,
	NODE4
};
#endif // !UTILS
