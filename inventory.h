#include "/public/read.h" // IWYU pragma: keep
#include <map>
#include <vector> // IWYU pragma: keep
using namespace std;

struct Item {
	string name;
	int amount;
	string description;
};

class inventoryBST {
	private:
	multimap<string, Item> item;

	public:
	template <typename T, typename K>
	void print(const multimap<T, K>& item) {
		if (item.empty()) {
			cout << "Inventory is empty.\n";
		return;
		}
		for (const auto& [name, details] : item) {
			cout << "[" << name << "] = " << details << endl;
		}
	}
};
