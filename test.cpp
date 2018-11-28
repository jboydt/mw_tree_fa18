#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "bstree.hpp"

#include <string>
using std::string;

TEST_CASE ("BSTree<int> constructor") {
  BSTree<int> tree;

  CHECK(tree.toString() == "");
  CHECK(tree.getNumNodes() == 0);
  
  tree.insert(-1);
  CHECK(tree.getNumNodes() == 1);
}

TEST_CASE ("BSTree<string> constructor") {
  BSTree<string> tree;

  CHECK(tree.toString() == "");
  CHECK(tree.getNumNodes() == 0);
  
  tree.insert("apple");
  CHECK(tree.getNumNodes() == 1);
  
  tree.insert("banana");
  tree.insert("strawberry");
  tree.insert("kiwi");
  tree.insert("dragon fruit");
  tree.insert("tomato");
  tree.insert("orange");
  
  tree.printInOrder();
  
  CHECK(tree.find("apple") == true);
  CHECK(tree.find("grape") == false);
}
