#pragma once

#include <iostream>
#include <string>
using std::cout;
using std::string;

template <class T>
class BSTree {
  public:
    BSTree() {
      numNodes = 0;
      root = nullptr;
    }

    void clear() {
      clear(root);
    }

  	bool find(T data) {
  		return find(root, data);
  	}

  	T* get(T data) {
  		return get(root, data);
  	}

  	void remove(T data) {
  		return remove(root, data);
  	}

    T findMin(T data) {
      xfindMin(root);
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
     }else if (data == n->data){
       return &data;
     }else if (data < n->data){
       return get(n->leftChild, data);
     } else if (data > n->data){
       return get(n->rightChild, data);
     }
    }

    void clear(Node*& n) {
      // TODO
    }

    bool remove(Node*& n, T& data) {
      if (n == nullptr) {
       return false;
      } 
      if (data < n->data) {
        return remove(n->leftChild, data);
      } else if (data > n->data) {
        return remove(n->rightChild, data);
      } else {
        // no children
        if (n->leftChild == nullptr && n->rightChild == nullptr) {
          delete n;
          n = nullptr;
          return true;
          // one child (right)
        } else if (n->leftChild == nullptr) {
          Node* temp = n;
          n = n->rightChild;
          delete temp;
          return true;
          // one child (left)
        } else if (n->rightChild == nullptr) {
          Node* temp = findMax(n->rightChild);
          n = findMax(n->rightChild);
          delete temp;
          return true;
          // two children
        } else {
          Node* temp = findMax(n->rightChild);
          n->data = temp->data;
          return remove(n->rightChild, temp->data);
        }
      }
      return false;
    }

    T findMax (Node*& n, T data) {
      if (n == nullptr) {
        return nullptr;
      }
      else if (data > n->data) {
        return findMax(n->rightChild, data);
      } else {
        n = findMax(n->rightChild, data);
      }
      return n->data;
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
  				printInOrder(n->rightChild);
  				cout << n->data << ' ';
  				printInOrder(n->leftChild);
  			}
  		}
  };
