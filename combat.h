//#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
//#include "class_slop.h"
#include <curses.h>
#include <string>
using namespace std;

void combat() {
	vector<string> battle_map {	
	"#################################################################################################",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                  ##                                                                           #",
	"#                  # #                                                                          #",
	"#                  #  #                                                                         #",
	"#                  #   ####                                                                     #",
	"#                  #       #                                                                    #",
	"#                  #       #                                                                    #",
	"#                  #       #                                      ###                           #",
	"#                  #########                                     ######                         #",
	"#                                                               ####                            #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                  ###    #                                                                     #",
	"#                 ##########                                                                    #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                     ######                    #",
	"#                                                                  ############                 #",
	"#                                                                ###          ###               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#                                                                                               #",
	"#################################################################################################"
	};
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
	//mvaddstr(2,20,"Jacob is really cool");//this displays a string at the cords
	//mvaddch(0,0,'0');//this does the same as above but for chars
	//mvaddch(0,maxLines, '7');
	for (int i = 0; i < battle_map.size(); i++) {
		string temp = battle_map.at(i);
		for(int j = 0; j < battle_map.at(i).size(); j++) {
			move(i,j);
			addch(temp.at(j));
		}
		//addstr(battle_map.at(i));
		//string temp = battle_map.at(i);
		//mvaddchstr(i, 0, battle_map.at(i));
	}
	getch();//waits for user key;
	endwin(); //basically exits curses mode and returns the terminal to normal;
}
