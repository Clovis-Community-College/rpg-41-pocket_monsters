#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
using namespace std;

class slop {//Actor class but my names are better
	protected:
		string name;
		int hp = 0;
		int instinct = 0;//speed/initiative/whichever one you are more familiar with
		//the current position of the hero/monster
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
		int get_instinct() const {
			return instinct;
		}
		void set_instintic(int temp){
			instinct = temp;
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
		int dmg = 0;//for damage if it does damage it is negative if it heals its positive and 0 is for moves that deal no damage
		bool special_effect = false;
		bool area_of_effect = false; //if this is true it means it can attack/heal everyone on one side of the battlefield
	public:
		enum STATUS {
			BUFF_ATTK,
			BUFF_INSTINCT,
			OMNI_BUFF,//this means it buffs all their stats
			DEBUFF_ATTK,
			DEBUFF_INSTINCT,
			OMNI_DEBUFF,
			TOXIC,//damage over time monsters and charcters will have different ones so each one will pick 
			HEALING_OVERTIME
		};
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
		bool has_special_effect() const {
			return special_effect;
		}
		void set_special_effect(bool temp) {
			special_effect = temp;
		}
		bool is_area_of_effect() const {
			return area_of_effect;
		}
		void set_area_of_effect(bool temp) {
			area_of_effect = temp;
		}
};

class Software_Engineers : public slop, public move {//Heroes class, again my naming scheme is better
	protected:
		vector<move> moves{3};
		STATUS sp_effect;
	public:
		void add_move(move &temp, int move_index) {
			moves.at(move_index) = temp;
		}
		move get_move(int move_index) const {
			return moves.at(move_index);
		}
		int apply_special_effect(STATUS temp){
			switch (temp) {
				case BUFF_ATTK:
					return 2;
			}
		}
};

class Kieth: public Software_Engineers {
	Kieth () {
		name = "Kieth";
		hp = 20;
		speed = 5;
		moves.at(0).set_move_name("Make Mod");
		moves.at(0).set_description("Elevates ally to Mod status boosting their stats");
		moves.at(0).set_dmg(0);
		moves.at(0).set_special_effect(true);
		moves.at(0).set_area_of_effect(true);
		moves.at(1).set_move_name("Debug");
		moves.at(1).set_description("Removes all bugs in code healing allies");
		moves.at(1).set_dmg(-2);
		moves.at(1).set_special_effect(false);
	}
};
class Bjarne: public Software_Engineers {
};
class Guava: public Software_Engineers {
};
class Mencareli: public Software_Engineers {
};
class Mark : public Software_Engineers {//uses tcg cards to cause different effects
};

class Doggos : public slop, public moves{//monster class
};

class The_Old_Yeller : public Doggos{
};
class German_Sheperd : public Doggos{
};
class Chihuahua : public Doggos{
};
class Husky : public Doggos {
};
class Turtle : public Doggos {
};
