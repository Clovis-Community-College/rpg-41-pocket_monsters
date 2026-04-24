//#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
//#include "class_slop.h"
#include <curses.h>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include "bridge_pain.h"
using namespace std;

void combat(map<string, Software_Engineers> &party) {
	vector<slop*> after_party = {new Kieth(), new Bjarne(), new Guava(), new Mencareli()};
	vector<slop*> dog_park = {new Turtle(), new Husky(), new Chihuahua(), new German_Sheperd()};
	Sphere foot_race(after_party, dog_park);
	srand(time(nullptr));
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
	};//97 across, 42 from top to bottom I believe
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
	party.at("Mencareli").set_battle_position(38, 39);
	move(38, 39);
	addch(party.at("Mencareli").get_sprite());
	party.at("Kieth").set_battle_position(38, 37);
	move(38, 37);
	addch(party.at("Kieth").get_sprite());
	party.at("Bjarne").set_battle_position(38, 41);
	move(38, 41);
	addch(party.at("Bjarne").get_sprite());
	party.at("Guava").set_battle_position(38, 43);
	move(38,43);
	addch(party.at("Guava").get_sprite());
	map <string, Doggos> pack = {
		{"Turtle", Turtle()},
		{"Husky", Husky()},
		{"Chihuahua", Chihuahua()},
		{"German_Sheperd", German_Sheperd()}
	};
	//TODO: add random sets of teams;
	/*for(int i = 0; i < 6; i++) {
		int who = rand()%3;
		if(who == 0) {
			pack.emplace("Turtle", Turtle());
		}
		else if(who == 1) {
			pack.emplace("Husky", Husky());
		}
		else if(who == 2) {
			pack.emplace("Chihuahua", Chihuahua());
		}
		else {
			pack.emplace("German Sheperd", German_Sheperd());
		}
	}*/
	pack.at("Turtle").set_battle_position(4,39);
	move(4,39);
	addch(pack.at("Turtle").get_sprite());
	pack.at("Husky").set_battle_position(4,37);
	move(4,37);
	addch(pack.at("Husky").get_sprite());
	pack.at("Chihuahua").set_battle_position(4,41);
	move(4,41);
	addch(pack.at("Chihuahua").get_sprite());
	pack.at("German_Sheperd").set_battle_position(4,43);
	move(4,43);
	addch(pack.at("German_Sheperd").get_sprite());
	for(;;) {

		break;
	}
	getch();//waits for user key;
	endwin(); //basically exits curses mode and returns the terminal to normal;
}
