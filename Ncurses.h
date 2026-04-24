#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
#include <ncurses.h>
#include <clocale>
#include <ctime>
#include <cstdlib>
//#include "combat.h"    //MAKE SURE TO UNCOMMENT THIS OUT TOO LOGAN!!
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

const int MAP_HEIGHT = 75;
const int MAP_WIDTH = 125;
const int VIEWER_LINES = 50;
const int VIEWER_COLS = 80;
const char EMPTY = '.';
const char PLAYER = 'P';
const char TREE = 'T';
const char BUSH = 'b';
const char ROCK = 'r';
const char DOGGO = 'D';
char map_data[MAP_HEIGHT][MAP_WIDTH];
int MAX_X{};
int MAX_Y{};

void create_map() {
	srand(time(NULL));
	initscr();
	nl();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK); //player
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK); //border 
	init_pair(3, COLOR_GREEN, COLOR_BLACK); //tree
	init_pair(4, COLOR_BLUE, COLOR_BLACK); //bush
	init_pair(5, COLOR_CYAN, COLOR_BLACK); //rock
	init_pair(6, COLOR_RED, COLOR_BLACK); // doggo
	init_pair(7, COLOR_WHITE, COLOR_BLACK); //empty
	WINDOW * map{};
	WINDOW * map_pad{};
	getmaxyx(stdscr, MAX_Y, MAX_X);
	int start_y = (MAX_Y - VIEWER_LINES) / 2;
	int start_x = (MAX_X - VIEWER_COLS) / 2;
	map = newwin(VIEWER_LINES + 2, VIEWER_COLS + 2, start_y, start_x);
	map_pad = newpad(MAP_HEIGHT, MAP_WIDTH); 
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				map_data[i][j] = EMPTY;
				mvwaddch(map_pad, i, j, EMPTY | COLOR_PAIR(7) | A_BOLD);
			}
		}
		for (int i = 0; i < 60; i++) {
			int randomx = rand() % MAP_WIDTH;
			int randomy = rand() % MAP_HEIGHT;
			map_data[randomy][randomx] = TREE;
			mvwaddch(map_pad, randomy, randomx, TREE | COLOR_PAIR(3));
		}
		for (int i = 0; i < 36; i++) {
			int randomx = rand() % MAP_WIDTH;
			int randomy = rand() % MAP_HEIGHT;
			map_data[randomy][randomx] = BUSH;
			mvwaddch(map_pad, randomy, randomx, BUSH | COLOR_PAIR(3) | A_BOLD);
		}
		for (int i = 0; i < 25; i++) {
			int randomx = rand() % MAP_WIDTH;
			int randomy = rand() % MAP_HEIGHT;
			map_data[randomy][randomx] = ROCK;
			mvwaddch(map_pad, randomy, randomx, ROCK | COLOR_PAIR(5));
		}
		for (int i = 0; i < 12; i++) {
			int randomx = rand() % MAP_WIDTH;
			int randomy = rand() % MAP_HEIGHT;
			map_data[randomy][randomx] = DOGGO;
			mvwaddch(map_pad, randomy, randomx, DOGGO | COLOR_PAIR(6));
		}
	int player_posy = VIEWER_LINES/2; 
	int player_posx = VIEWER_COLS/2; 
	int ch = 0;
	while (ch != 'q') {
		char original_char = map_data[player_posy][player_posx];
		int original_col = 0;
		if (original_char == TREE) {
			original_col = 3;
		}
		else if (original_char == BUSH) {
			original_col = 3;
		}
		else if (original_char == ROCK){
			original_col = 5;
		}
		else if (original_char == DOGGO) {
			original_col = 6;
		}
		else original_col = 7;
		mvwaddch(map_pad, player_posy, player_posx, original_char | COLOR_PAIR(original_col) | A_BOLD);
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
		if (map_data[player_posy][player_posx] == DOGGO) {
			clear();
			refresh();
			//combat();                                                //REMINDER FOR LOGAN: FIX THE COMBAT FUNCTION!!!!!!!!!!!!
			clear();
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
		mvwaddch(map_pad, player_posy, player_posx, 'P' | COLOR_PAIR(1) | A_BOLD);
		wattron(map, COLOR_PAIR(2));
		wborder(map, '|', '|', '-', '-', '+', '+', '+', '+');
		wattroff(map, COLOR_PAIR(2));
		wnoutrefresh(map);
		pnoutrefresh(map_pad, exception_case$, exception_case, start_y + 1, start_x + 1, start_y + VIEWER_LINES, start_x + VIEWER_COLS);
		doupdate();
		ch = getch();
	}
	endwin();
}


