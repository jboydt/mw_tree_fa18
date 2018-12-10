#include "bstree.hpp"
#include "word.h"

#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <ostream>
#include <sstream>
using std::istringstream;
using std::cout;
using std::endl;
using std::string;
using std::exception;
using std::ifstream;


template<class T>
class Treemaker {
	public:
		// load : accepts a file name and reads in commands
		void load (string filename){
			ifstream ifs;
			string command;
			ifs.open(filename);
			if (!ifs.fail()){
				while (!ifs.eof()) {
					getline (ifs, command);
					command[0] = toupper(command[0]);
					input(command);
				}
			} else {
				cout << "FILE FAILED TO OPEN" << endl;
			}
		}

		// toDatatype : converts part of file input argument to the correct datatype
		T toDatatype (string command){
			istringstream iss(command.substr(2));
			string usableData;
			iss >> usableData;
			return T(usableData);
		}

		// C : delete current tree (if any) and create a new tree
		void create (){
			if (planter != nullptr) {
				deleteTree();
			}
			planter = new BSTree<T>;
		}

		// D : delete tree and set planter to nullptr
		void deleteTree (){
			planter->clear();
			delete planter;
			planter = nullptr;

		}

		// input : calls functions from commands and handles outputs
		void input (string choice) {

			if (choice[0] == '#' || choice.length() == 0) {
				//ignore
			} else if (choice[0] == 'C') {
				create();
				cout << "TREE CREATED" << endl;
			} else if (planter == nullptr) {
				cout << "MUST CREATE TREE INSTANCE" << endl;
			} else if (choice[0] == 'X') {
				planter->clear();
				cout << "TREE CLEARED" << endl;
			} else if (choice[0] == 'D') {
				deleteTree();
				cout << "TREE DELETED" << endl;
			} else if (choice[0] == 'I') {
				T leaf = toDatatype(choice);
				if (planter->find(leaf)) {
					T* branch = planter->get(leaf);
					branch->incrementCount();
					cout << "WORD " << leaf.getWord() << " INCREMENTED" << endl;
				} else {
					planter->insert(leaf);
					cout << "WORD " << leaf.getWord() << " INSERTED" << endl;
				}
			} else if (choice[0] == 'F') {
				T leaf = toDatatype(choice);
				if (planter->getNumNodes() == 0) {
					cout << "TREE EMPTY" << endl;
				} else if (planter->find(leaf)) {
					cout << "FOUND " << leaf << endl;
				} else {
					cout << leaf << " NOT FOUND" << endl;
				}
			} else if (choice[0] == 'R') {
				T leaf = toDatatype(choice);
				if (planter->getNumNodes() == 0) {
					cout << "TREE EMPTY" << endl;
				} else if (planter->remove(leaf)) {
					cout << "REMOVED " << leaf.getWord() << endl;
				} else {
					cout << leaf.getWord() << " NOT FOUND" << endl;
				}
			} else if (choice[0] == 'G') {
				T leaf = toDatatype(choice);
				T* twig = planter->get(leaf);
				if (twig != nullptr) {
					cout << "GOT " << twig->getWord() << " " << twig->getCount() << endl;
				} else {
					cout << "ERROR: WORD COUNT NOT FOUND" << endl;
				}
			} else if (choice[0] == 'N') {
				cout << "TREE SIZE IS " << planter->getNumNodes() << endl;
			} else if (choice[0] == 'O') {
				if (planter->getNumNodes() == 0) {
					cout << "TREE EMPTY" << endl;
				} else {
					planter->printInOrder();
					cout << endl;
				}
			} else if (choice[0] == 'E') {
				if (planter->getNumNodes() == 0) {
					cout << "TREE EMPTY" << endl;
				} else {
					planter->printReverseOrder();
					cout << endl;
				}
			}

		}

	private:

		BSTree<T>* planter = nullptr;



};


int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << "PLEASE ENTER A SINGLE FILENAME" << endl;
	} else {
		Treemaker<Word> builder;
		builder.load(argv[1]);
	}
	return 0;

}
