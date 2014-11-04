#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class BinarySearchTree{

public:
	BinarySearchTree(void){
		root = NULL;
	}

	~BinarySearchTree(void){
		//delete root;
	}

	Node<T> *root;

	void insert(T data){
		insert(data, root);
	}

	void display(){
		display(root);
		cout << endl;
	}

	void search(T data){
		searchComplete = false;
		search(data, root);
		if (searchComplete == true){
			cout << "\"" << data << "\"" << " was found after examining " << nodes << " nodes." << endl;
		}
		else{
			cout << "\"" << data << "\"" << " was not found. Searched " << nodes << " nodes." << endl;
		}
	}

	int checkLevelFull(){
		return checkLevelFull(root);
	}

	int getNodes(){
		return getNodes(root);
	}

	int getHeight(){
		return getHeight(root);
	}

	friend ostream& operator<<(ostream &os, BinarySearchTree<T> tree){
		cout << "________________________________________________________________________________" << endl;
		tree.display();
		cout << "________________________________________________________________________________" << endl << endl;
		cout << "Tree details:" << endl << endl;
		cout << "Number of nodes: " << tree.getNodes() << endl;
		cout << "Height of tree: " << tree.getHeight() << endl;
		cout << "Level at which tree is full: " << tree.checkLevelFull() << endl;
		return os;
	}

private:
	int nodes = 0;
	bool searchComplete = false;

	void insert(T data, Node <T>* &root){
		if (root == NULL){
			root = new Node<T>(data);
		}
		else if (data <= root->data){
			insert(data, root->left);
		}
		else{
			insert(data, root->right);
		}
	}

	void display(Node <T>* &root){
		if (root != NULL){
			cout << root->data << " ";
			if (root->left != NULL){
				display(root->left);
			}
			if (root->right != NULL){
				display(root->right);
			}
		}
	}

	int getNodes(Node <T>* &root){
		int words = 0;
		if (root != NULL){
			words++;
			if (root->left != NULL){
				words += getNodes(root->left);
			}
			if (root->right != NULL){
				words += getNodes(root->right);
			}
		}
		return words;
	}

	void search(T data, Node <T>* &root){
		if (root != NULL){
			nodes++;
			if (root->data == data){
				searchComplete = true;
			}
			else{
				searchComplete = false;
				if (data <= root->data){
					search(data, root->left);
				}
				else{
					search(data, root->right);
				}
			}
		}
	}

	int checkLevelFull(Node<T>* &root){
		if (root == NULL){
			return 0;
		}
		if (root->left != NULL && root->right != NULL){
			return (checkLevelFull(root->left) + 1 + checkLevelFull(root->right));
		}
		else return 0;
	}
	int getHeight(Node<T>* &root)
	{
		if (root == NULL)
		{
			return 0;
		}

		int left = getHeight(root->left);
		int right = getHeight(root->right);

		if (left > right)
			return 1 + left;
		else
			return 1 + right;
	}
};








