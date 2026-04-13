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
		int movement = 0; //this is how many spaces each class can move within the battlefield
		int sick_days = 0;
	public:
	virtual ~slop() = default;
		enum SICKNESS {
			POISONED,
			HEMORAGE,
			WEAKNESS,
			SLOTH,
			CAFFIENATED,
			ROIDED,
			VITALITY
		};
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
		void set_y(int temp) {
			y = temp;
		}
		int get_movement() const {
			return movement;
		}
		void set_movement(int temp) {
			movement = temp;
		}
};

class move {
	protected:
		string move_name;
		string description;
		int dmg = 0;//for damage if it does damage it is negative if it heals its positive and 0 is for moves that deal no damage
		bool special_effect = false;
		bool area_of_effect = false; //if this is true it means it can attack/heal everyone on one side of the battlefield
		int range = 0;
	public:
		enum STATUS {
			BUFF_ATTK,
			BUFF_INSTINCT,
			OMNI_BUFF,//this means it buffs all their stats
			DEBUFF_ATTK,
			DEBUFF_INSTINCT,
			OMNI_DEBUFF,
			TOXIC,//damage over time monsters and charcters will have different ones so each one will pick 
			HEALING_OVERTIME,
			BLEED //TODO connect the bleed to hemorage 
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
		void is_special_effect(bool temp) {
			special_effect = temp;
		}
		bool is_area_of_effect() const {
			return area_of_effect;
		}
		void set_area_of_effect(bool temp) {
			area_of_effect = temp;
		}
		int get_range() const {
			return range;
		}
		void set_range(int temp) {
			range = temp;
		}
		void set_special_effect(STATUS temp) {
			sp_effect = temp;
		}
		STATUS get_special_effect() const {
			return sp_effect;
		}

		protected:
		STATUS sp_effect;
};

class Software_Engineers : public slop, public move {//Heroes class, again my naming scheme is better
	protected:
		vector<move> moves{3};
		//STATUS sp_effect;
	public:
		void add_move(move &temp, int move_index) {
			moves.at(move_index) = temp;
		}
		move get_move(int move_index) const {
			return moves.at(move_index);
		}
		float apply_special_effect(STATUS temp){
			switch (temp) {
				case BUFF_ATTK:
					return 2;
				case BUFF_INSTINCT:
					return 2;
				case OMNI_BUFF:
					return 1;
				case DEBUFF_ATTK:
					return -2;
				case DEBUFF_INSTINCT:
					return -2;
				case OMNI_DEBUFF:
					return -1;
				case TOXIC:
					return -0.5;
				case HEALING_OVERTIME:
					return 0.5;
			}
		}
};

class Kieth: public Software_Engineers {
	Kieth() {
		name = "Kieth";
		hp = 20;
		instinct = 5;
		moves.at(0).set_move_name("Make Mod");
		moves.at(0).set_description("Elevates ally to Mod status boosting their stats");
		moves.at(0).set_dmg(0);
		moves.at(0).is_special_effect(true);
		moves.at(0).set_special_effect(OMNI_BUFF);
		moves.at(0).set_area_of_effect(true);
		moves.at(0).set_range(3);
		moves.at(1).set_move_name("Debug");
		moves.at(1).set_description("Removes all bugs in code healing allies");
		moves.at(1).set_dmg(-2);
		moves.at(1).is_special_effect(false);
		moves.at(1).set_area_of_effect(false);
		moves.at(1).set_range(2);
		moves.at(3).set_move_name("SegFault");
		moves.at(3).set_description("Realeases toxins that makes the enemeies segfault irl causing them to grow weaker");
		moves.at(3).set_dmg(0);
		moves.at(3).is_special_effect(true);
		moves.at(3).set_special_effect(DEBUFF_ATTK);
		moves.at(3).set_area_of_effect(false);
		moves.at(3).set_range(4);
		//moves.at(2).set_move_name("
	}
};
class Bjarne: public Software_Engineers {//maybe make status its own class
	Bjarne() {
		name = "Bjarne";
		hp = 30;
		instinct = 3;
		moves.at(0).set_move_name("Shotgun");
		moves.at(0).set_description("shotgun");
		moves.at(0).set_dmg(6);
		moves.at(0).is_special_effect(false);
		moves.at(0).set_area_of_effect(false);
		moves.at(0).set_range(1);
		moves.at(1).set_move_name("G U N");
		moves.at(1).set_description("gun");
		moves.at(1).set_dmg(2);
		moves.at(1).is_special_effect(true);
		moves.at(1).set_special_effect(BLEED);
		moves.at(1).set_area_of_effect(true);
		moves.at(1).set_range(3);
		moves.at(2).set_move_name("ShOt");
		moves.at(2).set_description("shot");
		moves.at(2).set_dmg(4);
		moves.at(2).is_special_effect(false);
		moves.at(2).set_area_of_effect(false);
		moves.at(2).set_range(6);
	}
};
class Guava: public Software_Engineers {//AOE guy
	Guava() {
		name = "Guava";
		hp = 25;
		instinct = 3;
		moves.at(0).set_move_name("Garbage Collecter");
		moves.at(0).set_description("removes all ally afflictions good and bad");
		moves.at(0).set_dmg(0);
		moves.at(0).is_special_effect(true);
		moves.at(0).set_area_of_effect(true);
		moves.at(0).set_range(1);
		moves.at(1).set_move_name("Trash Panda Stampede");//plan is to make this a huge AOE
		moves.at(1).set_description("releases the rabies free raccoons from the garbage collector");
		moves.at(1).set_dmg(2);
		moves.at(1).is_special_effect(false);
		moves.at(1).set_area_of_effect(true);
		moves.at(1).set_range(3);
		moves.at(2).set_move_name("Raccoon Rain");
	}
};
class Mencareli: public Software_Engineers {
};
class Mark : public Software_Engineers {//uses tcg cards to cause different effects
};


class Doggos : public slop, public move{//monster class
	vector<move> moves{2};
};
class The_Old_Yeller : public Doggos{
	The_Old_Yeller() {
		name = "The Old Yeller";
		hp = 150;
		instinct = 5;
	}
};
class German_Sheperd : public Doggos{
	German_Sheperd() {
		name = "German_Sheperd";
		hp = 6;
		instinct = 2;
	}
};
class Chihuahua : public Doggos{
	Chihuahua() {
		name = "Chihuahua";
		hp = 3;
		instinct = 5;
	}
};
class Husky : public Doggos {
	Husky() {
		name = "Husky";
		hp = 8;
		instinct = 3;
	}
};
class Turtle : public Doggos {
	Turtle() {
		name = "Dog";
		hp = 15;
		instinct = 1;
	}
};
