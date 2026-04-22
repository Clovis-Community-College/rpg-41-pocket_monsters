//#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
//#include "class_slop.h"
#include <curses.h>
using namespace std;

void combat() {
	initscr();//tells curses what terminal we have so it knows our limits etc.
	//when you use initsrc it creates two variables called LINES and COLS which is how many lines and columns the terminal has
	//it starts at zero and goes up to the max size
	//for example at cols 0 it is the top left of the screen
	//and for lines 0 is the top of of the screen
	//we decrease it to one so it doesn't go outside of the screen since its kind of like size;
	int maxCol = COLS - 1;
	int maxLines = LINES - 1;
	cbreak();//disables line buffering
	noecho();//doesn't return the the user input to the screen
	clear();//clears the screen? its that or makes it transparent, idk man I don't read documentation 
	//curses keeps the prev version of the screen in memory unless you update it so it has some preformance upsides
	mvaddch(0,0,'0');
	mvaddch(0,maxLines, '7');
	getch();//waits for user key;
	endwin(); //basically exits curses mode and returns the terminal to normal;
}
