#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
using namespace std;

class slop {//Actor class but my names are better
	protected:
		string name;
		int hp = 0;
		int speed = 0;
		int x = 0;
		int y = 0;
	public:
		string get_name() const {
			return name;
		}
		void set_name(string temp) {
			name = temp;
		}
		int get_hp() const {
			return hp;
		}
		void set_hp(int temp) {
			hp = temp;
		}
		int get_speed() const {
			return speed;
		}
		void set_speed(int temp){
			speed = temp;
		}
		int get_x() const {
			return x;
		}
		void set_x(int temp) {
			x = temp;
		}
		int get_y() const {
			return y;
		}
		int set_y(int temp) {
			y = temp;
		}
};

class move {
	protected:
		string move_name;
		string description;
		int dmg = 0;//for damage if it does damage it is negative if it heals its positive
		bool status = false;
	public:
		/*(move(string temp_name = "none", string temp_descrription = "none", int temp_dmg = 0, bool temp_status = false) {
			move_name = temp_name;
			description = temp_descrription;
			dmg = temp_dmg;
			status = temp_status;
		}*/
		string get_move_name() const {
			return move_name;
		}
		void set_move_name(string temp) {
			move_name = temp;
		}
		string get_description() const {
			return description;
		}
		void set_description(string temp) {
			description = temp;
		}
		int get_dmg() const {
			return dmg;
		}
		void set_dmg(int temp) {
			dmg = temp;
		}
		bool is_status() const {
			return status;
		}
		void set_move_status(bool temp) {
			status = temp;
		}
};

class Software_Engineers : public slop, public move {//Heroes class, again my naming scheme is better
	protected:
		vector<move> moves{3};
	public:
		void add_move(move &temp, int move_index) {
			moves.at(move_index) = temp;
		}
		move get_move(int move_index) const {
			return moves.at(move_index);
		}
};

class Kieth: public Software_Engineers {
	Kieth () {
		name = "Kieth";
		hp = 20;
		speed = 5;
		moves.at(0).set_move_name("Make Mod");
		moves.at(0).set_description("Elevates ally to Mod status boosting to their stats");
		moves.at(0).set_dmg(0);
		moves.at(0).set_move_status(true);
		moves.at(1).set_move_name("Debug");
		moves.at(1).set_description("Removes all bugs in code healing allies");
		moves.at(1).set_dmg(-2);
		moves.at(1).set_move_status(false);
	}
};
class Bjarne: public Software_Engineers {
};
class Guava: public Software_Engineers {
};
class Mencareli: public Software_Engineers {
};
