#pragma once
#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
#include "Bridges.h"
#include "CircDLelement.h"
#include "class_slop.h"
using namespace std;
using namespace bridges;
using namespace datastructure;

void quicksort(vector<int> &array, vector<slop*> &peeps, int count) {
	int pivot = array.at(count - 1);
	slop pivotPeep = peeps.at(count - 1);
	int i, j;
	while (j > i) {
		while (array.at(i) < array.at(pivot)) {
			i++;
		}
		while (array.at(j) == pivot && j > i) {
			j--;
		}
		if (j > i) {
			slop swapPeep = peeps.at(i);
			peeps.at(i) = peeps.at(j);
			peeps.at(j) = swapPeep;
			int swap = array.at(i);
			array.at(i) = array.at(j);
			array.at(j) = swap;
		}
	}
	if (array.at(i) > pivot) {
		peeps.at(count-1) = peeps.at(i);
		peeps.at(i) = pivotPeep;
		array.at(count - 1) = array.at(i);
		array.at(i) = pivot;
	}
	quicksort(array, peeps, i);
	quicksort(array + (i + 1), count - (i + 1)); //TODO: figure out what array + (i + 1) does if array[]
}


class Sphere{//circular linked list and its info
	vector<slop*> softwareFolks;			//hero list 
	vector<slop*> possiblyEvilSoftwareFolks;//enemy list 
	CircDLelement<slop> *root;				//"first" element, just here for moral support
	CircDLelement<slop> *currentSloppy;		//iykyk
	int size = 0;

	public:
	Sphere(vector<slop*> &theGoodGuys, vector<slop*> &theBadGuys){
		vector<int> speeds;
		vector<int> massiveGuyVec;
		softwareFolks = theGoodGuys;
		possiblyEvilSoftwareFolks = theBadGuys;
		for(int i = 0; i < theGoodGuys.size(); i++){
			int speed = (rand() % 20) + theGoodGuys.at(i)->get_instinct();
			speeds.push_back(speed);
		}
		for(int i = 0; i < theBadGuys.size(); i++){
			int speed = rand() % 20 + theBadGuys.at(i)->get_instinct();
			speeds.push_back(speed);
		}
		quicksort(speeds, massiveGuyVec, massiveGuyVec.size());

		//TODO: initialize the stuff
	}


};
