#include "/public/read.h" // IWYU pragma: keep
#include <cstdlib>
#include "class_slop.h"
#include "/public/colors.h"
#include <chrono>
using namespace std;

void turned_based() {
	Mencareli mencareli;
	Guava guava;
	Bjarne bjarne;
	Kieth kieth;

	Turtle turtle;
	German_Sheperd german_sheperd;
	Chihuahua chihuahua;
	Husky husky;

	clearscreen();
	cout << "YOU HAVE ENTERED COMBAT" << endl;
	set_raw_mode(true);

	int good_alive = 4;
	int bad_alive = 4;
	char c;
	string monkey_type;

	while(true) {
		set_raw_mode(true);
		if(good_alive == 0 || c == 'q') {
			cout << "YOU LOST RETURN TO MONKE" << endl;
			exit(0);
		}
		if(bad_alive == 0) {
			cout << "GOOD JOB YOU PUT DOWN ALL THE DOGS" << endl;
			return;
		}
		cout << "press q to give up and e to attack" << endl;
		cin >> c;
		if(c == 'e') {
		}
		else {
			cout << "try reading the instructions for once" << endl;
			continue;
		}
		cout << "type enter we ready to fight" << endl;
		cin.ignore();
		cout << "type this text exactly and press enter when you are done" << endl;
		cout << "we should not use AI to cheat on our CEs" << endl;
		set_raw_mode(false);
		auto start = chrono::high_resolution_clock::now();
		getline(cin, monkey_type);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> time_wasted = end - start;
		double time = time_wasted.count();
		double wpm = 8/(time/60.0);
		if(wpm > 40 && monkey_type == "we should not use AI to cheat on our CEs") {
			cout << "VICTORY: you can type faster than a dog" << endl;
			return;
		}
		else {
			cout << "ooooof someone in your party died" << endl;
			good_alive--;
		}
	}

}
