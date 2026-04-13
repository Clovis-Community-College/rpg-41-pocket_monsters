#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
#include <ncurses.h>
using namespace std;

const int MAP_HEIGHT = 30;
const int MAP_WIDTH = 80;
const int VIEWER_LINES = 16;
const int VIEWER_COLS = 41;
int MAX_X{};
int MAX_Y{};

//Q's advice (below)
//renderworld and renderplay 
//^^^this function has a nested for loop that creates the actual map itself
//make a function for rendering where you are (displaying where you are on the map/window
//make a function for moving (changing x, y)

//Game Logic:
//1. Get Input (did they hit an arrow key?)
//2. Update Logic (move the player x , y)
//3. Render(draw the map) *similar to what Q said
//4. Refresh (making ncurses showing the changes you made)

void create_map() {
	initscr();
	nl();
	cbreak();
	noecho();
	WINDOW * map_window{};
	getmaxyx(map_window, MAX_Y, MAX_X);
	map_window = newwin(VIEWER_LINES, VIEWER_COLS, MAX_Y/2, MAX_X/2); 
	move(MAX_Y, MAX_X);

	//do the map now

	endwin();
}


