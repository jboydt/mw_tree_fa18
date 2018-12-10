#pragma once

#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;

template <class T>
class BSTree {
  public:
    BSTree() {
      numNodes = 0;
      root = nullptr;
    }

    // Maybe Needed??
    ~BSTree() {
      // TO DO??
    }

    void clear() {
      clear(root);
    }

    // Maybe Needed??
    bool empty() {
      if (numNodes == 0) {
        return true;
      }
      return false;
    }

  	bool find(T data) {
  		return find(root, data);
  	}

  	T* get(T data) {
  		return get(root, data);
  	}

  	bool remove(T data) {
  		return remove(root, data);
  	}

	void removeMax(T data) {
		return remove(root, data);
	}

  	void printReverseOrder() {
  		printReverseOrder(root);
  	}

  	void insert(T newData) {
  		insert(root, newData);
  	}

    unsigned int getNumNodes() {
      return numNodes;
    }

  	void printInOrder() {
  		printInOrder(root);
  	}

  private:
    unsigned int numNodes;
    struct Node {
      T data;
      Node* leftChild;
      Node* rightChild;

      Node(T newData) {
        data = newData;
        leftChild = nullptr;
        rightChild = nullptr;
      }
    } *root;

	T* get(Node* n, T data) {
		if (n == nullptr){
			return nullptr;
		} else if (data == n->data) {
			return &(n->data);
		}else if (data < n->data){
			return get(n->leftChild, data);
		} else if (data > n->data){
			return get(n->rightChild, data);
		}
	}

	void clear(Node*& n) {
		if(n != nullptr) {
			if(n->leftChild != nullptr)
			clear(n->leftChild);
			if(n->rightChild != nullptr)
			clear(n->rightChild);
			delete n;
			n = nullptr;
			numNodes--;
		}
	}

	bool remove(Node*& n, T& data) {
		if (n == nullptr) {
			return false;
		} else if (n->data < data) {
			return remove(n->rightChild, data);
		} else if (n->data > data) {
			return remove(n->leftChild, data);
		} else {
			if (n->leftChild == nullptr) {//&& n->rightChild == nullptr) {
			Node* temp = n;
			n = temp->rightChild;
			delete temp;
			numNodes--;
			return true;
			} else {
				removeMax(n->leftChild, n->data);
				numNodes--;
				return true;
			}
		}
	}

	void removeMax(Node*& root_ptr, T& removed) {
		if (root_ptr->rightChild == nullptr) {
			Node* temp = root_ptr;
			removed = root_ptr->data;
			root_ptr = root_ptr->leftChild;
			delete temp;
		} else {
			removeMax(root_ptr->rightChild, root_ptr->data);
		}
	}

	bool find(Node* n, T data) {
		// TODO (also recursive version)
		if (n == nullptr){
			return false;
		} else if (data == n->data) {
			return true;
		} else if (data < n->data) {
			return find(n->leftChild, data);
		} else if (data > n->data) {
			return find(n->rightChild, data);
		}
	}

	void insert(Node*& n, T newData) {
		if (n == nullptr) {
			n = new Node(newData);
			numNodes++;
		} else if (newData < n->data) {
			insert(n->leftChild, newData);
		} else if (newData > n->data) {
			insert(n->rightChild, newData);
		} else {
			// do nothing
		}
	}

	void printInOrder(Node* n) {
		if (n != nullptr) {
			printInOrder(n->leftChild);
			cout << n->data << ' ';
			printInOrder(n->rightChild);
		}
	}

	void printReverseOrder(Node* n) {
		if (n != nullptr) {
			printReverseOrder(n->rightChild);
			cout << n->data << ' ';
			printReverseOrder(n->leftChild);
		}
	}
};
