#include "/public/read.h" // IWYU pragma: keep
#include <memory>
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
		int batt_col = 0;
		int batt_line = 0;
		char sprite = '?';
		bool life = true;//if false they are dead
	public:
	virtual ~slop() = default;
		bool rabies = false;
		enum SICKNESS {
			POISONED,
			HEMORAGE,
			WEAKNESS,
			SLOTH,
			CAFFIENATED,
			ROIDED,
			VITALITY
		};
		bool is_dead() const {
			return life;
		}
		void set_life(bool death) {
			life = death;
		}
		char get_sprite() const {
			return sprite;
		}
		void set_sprite(char c) {
			sprite = c;
		}
		void set_battle_position(int col, int line) {
			batt_col = col;
			batt_line = line;
		}
		int get_batt_col() const {
			return batt_col;
		}
		int get_batt_line() const {
			return batt_line;
		}
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
		//bool area_of_effect = false; //if this is true it means it can attack/heal everyone on one side of the battlefield
		int range = 0;
		tuple <int,int,int,int> area_of_effect;//this will be the area that the attack/ability will cover
		//first number is up, second is down, third is left, and fourth is the right
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
class Make_Mod: public move {
	public:
	Make_Mod() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "Make Mod";
		description = "Elevates ally to Mod status boosting their stats";
		dmg = 0;
		special_effect = true;
		sp_effect = OMNI_BUFF;
		range = 3;
		up = 0;
		down = 0;
		left = 0;
		right = 0;
	}
};
class Debug: public move {
	public:
		Debug() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "Debug";
		description = "Removes all bugs in code healing allies";
		range = 2;
		dmg = -2;
		special_effect = false;
		up = 0;
		down = 0;
		left = 2;
		right = 2;
		}
		
};
class SegFault: public move { 
	public:
		SegFault() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "SegFault";
		description = "Realeases toxins that makes the enemeies segfault irl causing them to grow weaker";
		dmg = 0;
		special_effect = true;
		sp_effect = DEBUFF_ATTK;
		range = 4;
		up = 1;
		down = 1;
		left = 2;
		right = 2;
		}
};
class Kieth: public Software_Engineers {
	public:
		Make_Mod make_mode();
		Debug debug();
		SegFault segfault();
		Kieth() {
			name = "Kieth";
			hp = 20;
			instinct = 5;
			sprite = 'K';
			movement = 10;
		}
};
class Shotgun: public move {
	Shotgun() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "Shotgun";
		description = "shotgun";
		dmg = 6;
		special_effect = false;
		range = 1;
		up = 0;
		down = 0;
		left = 1;
		right = 1;
	}
};
class G_U_N: public move {
	G_U_N() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "G U N";
		description = "gun";
		dmg = 2;
		special_effect = true;
		sp_effect = BLEED;
		range = 3;
		up = 1;
		down = 1;
		left = 1;
		right = 1;
	}
};
class ShOt: public move {
	ShOt() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "ShOt";
		description = "shot";
		dmg = 4;
		special_effect = false;
		range = 6;
		up = 0;
		down = 0;
		left = 0;
		right = 0;
	}
};
class Bjarne: public Software_Engineers {//maybe make status its own class
	public:
	Shotgun shotgun();
	G_U_N gun();
	ShOt shot();
		Bjarne() {
			name = "Bjarne";
			hp = 30;
			instinct = 3;
			sprite = 'B';
			movement = 5;
		}
};
class Garbage_Collector: public move {
	Garbage_Collector() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "Garbage Collector";
		description = "removes all ally afflictions good and bad";
		dmg = 0;
		special_effect = true;
		range = 1;
		up = 2;
		down = 2;
		left = 3;
		right = 3;
	};
};
class Trash_Panda_Stampede: public move {
	Trash_Panda_Stampede() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "Trash Panda Stampede";
		description = "realeases the rabies free racoons from the grabage collector";
		dmg =  2;
		special_effect = false;
		range = 4;
		up = 3;
		down = 3;
		left = 3;
		right = 3;
	};
};
class Guava: public Software_Engineers {//AOE guy
	public:
		Garbage_Collector garbage_collector();
		Trash_Panda_Stampede trash_panda_stampede();
		Guava() {
			name = "Guava";
			hp = 25;
			instinct = 3;
			sprite = 'G';
			movement = 3;
		}
};
class Rage_Bait: public move {
	Rage_Bait() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "Rage Bait";
		description = "infuriates the enemy by calling them bald";
		dmg = 1;
		special_effect = true;
		//TODO: add the bait status effect
		range = 1;
		up = 0;
		down = 0;
		left = 2;
		right = 2;
	}
};
class Master_Bait: public move {
	Master_Bait() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "Master Bait";
		description = "So masterful at baiting the mind poisoning becomes physical";
		dmg = 1;
		special_effect = true;
		sp_effect = TOXIC;
		range = 2;
		up = 2;
		down = 0;
		left = 1;
		right = 1;
	}
};
class All_Rage_No_Bait: public move {
	 All_Rage_No_Bait() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "All Rage No Bait";
		description = "Now that you have baited them its time to rage";
		dmg = 3;
		special_effect = true;
		sp_effect = BUFF_ATTK;
		range = 1;
		up = 1;
		down = 0;
		left = 2;
		right = 2;
	 }
};
class Mencareli: public Software_Engineers {
	public:
		Rage_Bait rage_bait();
		Master_Bait master_bait();
		All_Rage_No_Bait all_rage_no_bait();
		Mencareli() {
			name = "Mencareli";
			hp = 50;
			instinct = 1;
			sprite = 'M';
			movement = 7;
		}
};
class Mark : public Software_Engineers {//uses tcg cards to cause different effects
};


class Doggos : public slop, public move{//monster class
	vector<move> moves{2};
	public:
};
class Rabies_Foam: public move {
	public:
	Rabies_Foam() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "Rabies_Foam";
		description = "spews the foam coming out of their mouth because of the rabies";
		dmg = 7;
		special_effect = false;
		range = 3;
		up = 1;
		down = 0;
		right = 4;
		left = 4;
	}
};
class The_Old_Yeller : public Doggos{
	public:
	Rabies_Foam rabies_foam();
	The_Old_Yeller() {
		name = "The Old Yeller";
		hp = 150;
		instinct = 5;
		sprite = 'Y';
		rabies = true;
	}
};
class Sieg_Heil: public move {
	public:
	Sieg_Heil() {
		auto& [up, down, left, right] = area_of_effect;
		move_name = "Sieg Heil";
		description = "barks in salute for victory";
		dmg = 2;
		special_effect = false;
		range = 2;
		up = 2;
		down = 0;
		right = 3;
		left = 3;
	}
};
class German_Sheperd : public Doggos{
	public:
	Sieg_Heil sieg_hiel();
	German_Sheperd() {
		name = "German_Sheperd";
		hp = 6;
		instinct = 2;
		sprite = 'N';
		rabies = true;
	}
};
class Yo_Quiero_Taco_Bell : public move {
	public:
	Yo_Quiero_Taco_Bell() {
		auto& [up,down,right,left] = area_of_effect;
		move_name = "Yo Quiero Taco Bell";
		description = "yO quIErO TAAAco BelL";
		dmg = 4;
		special_effect = false;
		range = 2;
		up = 1;
		down = 0;
		left = 0;
		right = 0;
	}
};
class Chihuahua : public Doggos{
	public:
	Yo_Quiero_Taco_Bell yo_quiero_taco_bell();
	Chihuahua() {
		name = "Chihuahua";
		hp = 3;
		instinct = 5;
		sprite = 'c';
		rabies = true;
	}
};
class Pup_Cup: public move {
	public:
	Pup_Cup() {
		auto& [up,down,right,left] = area_of_effect;
		move_name = "Pup Cup";
		description = "freezes you over with the frost breath creating from eating way too many pup cups";
		dmg = 2;
		special_effect = true;
		//add frostbite special effect
		range = 3;
		up = 2;
		right = 3;
		left = 3;
		down = 0;
	}
};
class Husky : public Doggos {
	public:
	Pup_Cup pup_cup();
	Husky() {
		name = "Husky";
		hp = 8;
		instinct = 3;
		sprite = 'H';
		rabies = true;
	}
};
class Beyblade: public move {
	public:
	Beyblade() {
		auto& [up,down,right,left] = area_of_effect;
		move_name = "Beyblade";
		description = "Beyblade Mode ENGAAAAAGE!!!!";
		dmg = 1;
		special_effect = false;
		range = 0;
		up = 4;
		down = 4;
		right = 4;
		left = 4;
	}
};
class Turtle : public Doggos {
	public:
		Beyblade beyblade();
	Turtle() {
		name = "Dog";
		hp = 15;
		instinct = 1;
		sprite = 'D';
		rabies = true;
	}
};
