#pragma once
#include "/public/read.h" // IWYU pragma: keep
#include <thread>
#include <vector>         // IWYU pragma: keep
#include "Bridges.h"
#include "CircDLelement.h"
#include "class_slop.h"
using namespace std;
using namespace bridges;
using namespace datastructure;

void quicksort(vector<int> &array, vector<slop*> &peeps, int count) {
	if(count < 2) return;
	cout << count << endl;
	this_thread::sleep_for(1s);
	int pivot = array.at(count - 1);
	slop *pivotPeep = peeps.at(count - 1);
	int i = 0, j = count - 1;
	while (j > i) {
		while (array.at(i) < pivot) {
			i++;
		}
		while (array.at(j) >= pivot && j > i) {
			j--;
		}
		if (j > i) {
			slop *swapPeep = peeps.at(i);
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
	vector<int> splitArrayOne;
	vector<int> splitArrayTwo;
	vector<slop*> splitPeepsOne;
	vector<slop*> splitPeepsTwo;
	for(int k = 0; k < array.size(); k++){
		if(k < i){
			splitArrayOne.push_back(array.at(k));
			splitPeepsOne.push_back(peeps.at(k));
		} else {
			splitArrayTwo.push_back(array.at(k));
			splitPeepsTwo.push_back(peeps.at(k));
		}
	}
	quicksort(splitArrayOne, splitPeepsOne, i);
	quicksort(splitArrayTwo, splitPeepsTwo, count - (i + 1)); //TODO: figure out what array + (i + 1) does if array[]
	for(int k = 0; k < array.size(); k++){
		if(k < i){
			array.at(k) = splitArrayOne.at(k);
			peeps.at(k) = splitPeepsOne.at(k);
		} else if(k > i) {
			array.at(k) = splitArrayTwo.at(k - i - 1);
			peeps.at(k) = splitPeepsTwo.at(k - i - 1);
		} else {
			array.at(k) = pivot;
			peeps.at(k) = pivotPeep;
		}
	}
	/*for(int k = array.size() - 1; k >= 0; k--){
		cout << k << endl;
		if(k < i){
			delete splitPeepsOne.at(k);
		} else if(k > i) {
			delete splitPeepsTwo.at(k - i);
		} else {
			delete pivotPeep;
		}

	}*/

}



class Sphere{//circular linked list and its info
	vector<slop*> softwareFolks;			//hero list 
	vector<slop*> possiblyEvilSoftwareFolks;//enemy list 
	CircDLelement<slop*> *root;				//"first" element, just here for moral support
	CircDLelement<slop*> *currentSloppy;		//iykyk
	int size = 0;

	public:
	Sphere(vector<slop*> &theGoodGuys, vector<slop*> &theBadGuys){
		vector<int> speeds;
		vector<slop*> massiveGuyVec;
		softwareFolks = theGoodGuys;
		possiblyEvilSoftwareFolks = theBadGuys;
		for(int i = 0; i < theGoodGuys.size(); i++){
			int speed = (rand() % 20) + theGoodGuys.at(i)->get_instinct();
			speeds.push_back(speed);
			massiveGuyVec.push_back(theGoodGuys.at(i));
		}
		for(int i = 0; i < theBadGuys.size(); i++){
			int speed = rand() % 20 + theBadGuys.at(i)->get_instinct();
			speeds.push_back(speed);
			massiveGuyVec.push_back(theBadGuys.at(i));
		}
		cout << "There are " << massiveGuyVec.size() << " creatures in combat\n";
		if(!massiveGuyVec.size()) return;
		quicksort(speeds, massiveGuyVec, massiveGuyVec.size());
		for(int i = 0; i < massiveGuyVec.size(); i++){
			cout << massiveGuyVec.at(i)->get_name() << " is moving at " << speeds.at(i) << " mph\n";
			if(i == 0) {
				root = new CircDLelement<slop*>;
				root->setValue(massiveGuyVec.at(i));
				root->setPrev(root);
				root->setNext(root);
				currentSloppy = root;
			} else {
				currentSloppy->setNext(new CircDLelement<slop*>);
				currentSloppy->getNext()->setPrev(currentSloppy);
				currentSloppy = currentSloppy->getNext();
				currentSloppy->setValue(massiveGuyVec.at(i));
				currentSloppy->setNext(root);
				root->setPrev(currentSloppy);
			}
		}
		
		//TODO: initialize the stuff
	}
	
	~Sphere(){
		CircDLelement<slop*> *curNode = currentSloppy;
		CircDLelement<slop*> *nextNode;
		CircDLelement<slop*> *prevNode;
		while(curNode){
			if(curNode->getNext() == curNode){
				delete curNode;
				return;
			}
			prevNode = curNode->getPrev();
			nextNode = curNode->getNext();
			nextNode->setPrev(prevNode);
			prevNode->setNext(nextNode);
			delete curNode;
			curNode = nextNode;
		}
	}
	

};
