#include "/public/read.h" // IWYU pragma: keep
#include <map>
#include <vector> // IWYU pragma: keep
using namespace std;

struct Object {
	string name;
	int amount;
	int cost;
	bool key_item = false;
	Object *right = nullptr;
	Object *left = nullptr;

};

class inventory {
	private:
		Object *root = nullptr;
	public:
		void insert(Object *temp) {
			if(root == nullptr) {
				root = temp;
				return;
			}
			Object *cur = root;
			while(true) {
				if(temp->name == cur->name) {
					cur->amount++;
					return;
				}
				if(temp->name > cur->name) {
					if(cur->right == nullptr) {
						cur->right = temp;
						return;
					}
					temp = cur->right;
				}
				else {
					if(cur->left == nullptr) {
						cur->left = temp;
						return;
					}
					temp = cur->left;
				}
			}
		}
		void print() const{
			if(root != nullptr) {
				print(root);
			}
		}
		void print(Object *cur) const {
			if(cur == nullptr) {
				return; 
			}
			print(cur->left);
			cout << "Item Name: " << cur->name << " Value: " << cur->cost << " Amount: " << cur->amount << endl;
			print(cur->right);
		}
};
