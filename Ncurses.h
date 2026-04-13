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
void worldGeneration() {
	//TODO:
	/*Create a vector<string> or vector<vector<char>>
	and make a nested for loop that generates the 
	map and its size*/
}

int XPosition() {
	//TODO:
	//after map generation, return the 
	//x position of the character 
	//in relation from the bigger map_window
	//so that you can get it in terms of 
	//just x instead of a char
}

int YPosition() {
	//TODO:
	//same thing as above
	//but for y position
}

void create_map() {
	initscr();
	nl();
	cbreak();
	noecho();
	WINDOW * map_pad{};
	getmaxyx(map_pad, MAX_Y, MAX_X);
	map_pad = newpad(VIEWER_LINES, VIEWER_COLS); 
	move(MAX_Y, MAX_X);
	refresh();

	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			// waddch (map_pad, finish the rest of this for map generation)
		}
	}
	int cur_y = MAX_Y/2;
	int cur_x = MAX_X/2; 
	int leftcol = '|';
	int rightcol = '|';
	int toprow = '-';
	int btmrow = '-';
	int tlc = '=';
	int trc = '=';
	int blc = '=';
	int brc = '=';
	wborder(map_pad, leftcol, rightcol, toprow, btmrow, tlc, trc, blc, brc);
	mvwprintw(map_pad, VIEWER_LINES/2, VIEWER_COLS/2, "Welcome to the Game");
	wrefresh(map_pad);
	int ch = getch();
	//take input for arrow keys
	while (ch != 'q') {
		if (ch == KEY_UP) {
			if (cur_y > 0) cur_y--;
			break;
		}
	}
	endwin();
}


