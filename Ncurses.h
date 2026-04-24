#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
#include <ncurses.h>
#include <clocale>
using namespace std;

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

const int MAP_HEIGHT = 40;
const int MAP_WIDTH = 90;
const int VIEWER_LINES = 26;
const int VIEWER_COLS = 53;
const char EMPTY = '.';
int MAX_X{};
int MAX_Y{};

void create_map() {
	initscr();
	nl();
	cbreak();
	noecho();

	WINDOW * map{};
	WINDOW * map_pad{};
	getmaxyx(stdscr, MAX_Y, MAX_X);
	int start_y = (MAX_Y - VIEWER_LINES) / 2;
	int start_x = (MAX_X - VIEWER_COLS) / 2;
	map = newwin(VIEWER_LINES + 2, VIEWER_COLS + 2, start_y, start_x);
	map_pad = newpad(MAP_HEIGHT, MAP_WIDTH); 
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			mvwaddch(map_pad, i, j, EMPTY);
			}
	}
	int player_posy = VIEWER_LINES/2; 
	int player_posx = VIEWER_COLS/2; 
	int ch{};
	while (ch != 'q') {
		if (ch == KEY_UP) {
			if (player_posy > 0) player_posy--;
		}
		if (ch == KEY_DOWN) {
			if (player_posy < (MAP_HEIGHT - 1)) player_posy++;
		}
		if (ch == KEY_LEFT) {
			if (player_posx > 0) player_posx--;
		}
		if (ch == KEY_RIGHT) {
			if (player_posx < (MAP_WIDTH - 1)) player_posx++;
		}
		int exception_case = player_posx - (VIEWER_COLS/2);
		int exception_case$ = player_posy - (VIEWER_COLS/2);
		if (exception_case < 0) {
			exception_case = 0;
		}
		if (exception_case > (MAP_WIDTH - VIEWER_COLS)) {
			exception_case = MAP_WIDTH - VIEWER_COLS;
		}
		if (exception_case$ < 0) {
			exception_case$ = 0;
		}
		if (exception_case$ > (MAP_HEIGHT - VIEWER_LINES)) {
			exception_case$ = MAP_HEIGHT - VIEWER_LINES;
		}
		wborder(map, '|', '|', '-', '-', '+', '+', '+', '+');
		wnoutrefresh(map);
		pnoutrefresh(map_pad, exception_case$, exception_case, start_y + 1, start_x + 1, start_y + VIEWER_LINES, start_x + VIEWER_COLS);
		doupdate();
		ch = getch();
	}
	endwin();
}


