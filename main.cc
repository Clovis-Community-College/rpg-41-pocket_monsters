#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
//#include "class_slop.h"
#include "bridge_pain.h"
#include "inventory.h"
#include "Ncurses.h"
#include "combat.h"
#include <map>
using namespace std;

int main() {
	Kieth kieth;
	Mencareli mencareli;
	Bjarne bjarne;
	Guava guava;

	combat(kieth, mencareli, bjarne, guava);
}
