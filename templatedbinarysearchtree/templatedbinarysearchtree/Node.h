template <class T>
class Node{
public:
	Node* left;
	Node* right;
	T data;

	Node(void){
		left = NULL;
		right = NULL;
	}
	Node(T item){
		data = item;
		left = NULL;
		right = NULL;
	}

	~Node(void){
		delete left;
		delete right;
	}

};
