#pragma once
#include "/public/read.h" // IWYU pragma: keep
#include <memory>
#include <thread>
#include <vector>         // IWYU pragma: keep
#include "Bridges.h"
#include "CircDLelement.h"
#include "class_slop.h"
using namespace std;
using namespace bridges;
using namespace datastructure;

void visualizer(Bridges &b, CircDLelement<shared_ptr<slop>> *curNode){
	CircDLelement<shared_ptr<slop>> *savNode = curNode;
	curNode = curNode->getNext();
	savNode->setColor("red");
	savNode->getLinkVisualizer(curNode)->setColor("green");
	for(; curNode != savNode; curNode = curNode->getNext()){
		curNode->setColor("aliceblue");
		curNode->getLinkVisualizer(curNode->getNext())->setColor("magenta");
	}
	b.setDataStructure(savNode);
	b.visualize();
	curNode = savNode;
}

void quicksort(vector<int> &array, vector<shared_ptr<slop>> &peeps, int count) {
	if(count < 2) return;
	int pivot = array.at(count - 1);
	shared_ptr<slop> pivotPeep = peeps.at(count - 1);
	int i = 0, j = count - 1;
	while (j > i) {
		while (array.at(i) < pivot) {
			i++;
		}
		while (array.at(j) >= pivot && j > i) {
			j--;
		}
		if (j > i) {
			shared_ptr<slop> swapPeep = peeps.at(i);
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
	vector<shared_ptr<slop>> splitPeepsOne;
	vector<shared_ptr<slop>> splitPeepsTwo;
	for(int k = 0; k < array.size(); k++){
		if(k < i){
			splitArrayOne.push_back(array.at(k));
			splitPeepsOne.emplace_back(peeps.at(k));
		} else {
			splitArrayTwo.push_back(array.at(k));
			splitPeepsTwo.emplace_back(peeps.at(k));
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
}



class Sphere{//circular linked list and its info
	vector<shared_ptr<slop>> softwareFolks;			//hero list 
	vector<shared_ptr<slop>> possiblyEvilSoftwareFolks;//enemy list 
	CircDLelement<shared_ptr<slop>> *root;				//"first" element, just here for moral support
	CircDLelement<shared_ptr<slop>> *currentSloppy;		//iykyk
	Bridges bridges;//2, "falseP0tato" ,"1041388770783");
	int size = 0;

	public:
	Sphere(vector<shared_ptr<slop>> &theGoodGuys, vector<shared_ptr<slop>> &theBadGuys): softwareFolks(theGoodGuys), possiblyEvilSoftwareFolks(theBadGuys), bridges(1, "falseP0tato","1041388770783") {
		vector<int> speeds;
		vector<shared_ptr<slop>> massiveGuyVec;
		//softwareFolks = theGoodGuys;
		//possiblyEvilSoftwareFolks = theBadGuys;
		for(int i = 0; i < theGoodGuys.size(); i++){
			int speed = (rand() % 20) + theGoodGuys.at(i)->get_instinct();
			speeds.push_back(speed);
			massiveGuyVec.emplace_back(theGoodGuys.at(i));
			size++;
		}
		for(int i = 0; i < theBadGuys.size(); i++){
			int speed = rand() % 20 + theBadGuys.at(i)->get_instinct();
			speeds.push_back(speed);
			massiveGuyVec.push_back(theBadGuys.at(i));
			size++;
		}
		cout << "There are " << massiveGuyVec.size() << " creatures in combat\n";
		if(!massiveGuyVec.size()) return;
		quicksort(speeds, massiveGuyVec, massiveGuyVec.size());
		for(int i = 0; i < massiveGuyVec.size(); i++){
			cout << massiveGuyVec.at(i)->get_name() << " is moving at " << speeds.at(i) << " mph\n";
			if(i == 0) {
				root = new CircDLelement<shared_ptr<slop>>;
				root->setValue(massiveGuyVec.at(i));
				root->setLabel(massiveGuyVec.at(i)->get_name());
				root->setPrev(root);
				root->setNext(root);
				currentSloppy = root;
			} else {
				currentSloppy->setNext(new CircDLelement<shared_ptr<slop>>);
				currentSloppy->getNext()->setPrev(currentSloppy);
				currentSloppy = currentSloppy->getNext();
				currentSloppy->setValue(massiveGuyVec.at(i));
				currentSloppy->setLabel(massiveGuyVec.at(i)->get_name());
				currentSloppy->setNext(root);
				root->setPrev(currentSloppy);
			}
		}
		currentSloppy = root;	
		visualizer(bridges, currentSloppy);
		//TODO: initialize the stuff
	}
	void deleteSlop(){
		if(currentSloppy == nullptr) return;
		if(currentSloppy->getNext() == currentSloppy){
			delete currentSloppy;
			currentSloppy = nullptr;
			root = nullptr;
			return;
		}
		CircDLelement<shared_ptr<slop>> *nextSlop = currentSloppy->getNext();
		CircDLelement<shared_ptr<slop>> *prevSlop = currentSloppy->getPrev();
		prevSlop->setNext(nextSlop);
		nextSlop->setPrev(prevSlop);
		delete currentSloppy;
		currentSloppy = nextSlop;
		size--;
		visualizer(bridges, currentSloppy);
	}
	void nextTurn(){
		currentSloppy = currentSloppy->getNext();
		visualizer(bridges, currentSloppy);
	}
	shared_ptr<slop> getSlop (){
		return (currentSloppy->getValue());
	}
	~Sphere(){
		CircDLelement<shared_ptr<slop>> *curNode = currentSloppy;
		CircDLelement<shared_ptr<slop>> *nextNode;
		CircDLelement<shared_ptr<slop>> *prevNode;
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
