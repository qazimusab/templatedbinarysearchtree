// templatedbinarysearchtree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void readFile();

BinarySearchTree<string> tree;

int _tmain(int argc, _TCHAR* argv[]){
	try{
		readFile();
		cout << tree << endl;
		tree.search("decleration");
	}
	catch (exception& e){

		cout << "Exception occurred." << endl;
	}

	system("pause");
	return 0;
}

void readFile(){
	ifstream file;
	file.open("Independence.txt");
	if (file.is_open()){
		string word;
		while (file >> word){
			for (unsigned int i = 0; i < word.size(); i++){
				if (!isalnum(word[i])){
					word.erase(i, 1);
					i--;
				}
			}
			tree.insert(word);
		}
	}
}

