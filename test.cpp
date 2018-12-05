#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "bstree.hpp"
#include "word.h"

#include <string>
using std::string;

/*TEST_CASE("BSTree<Word>") {
  BSTree<Word> tree;

  tree.insert(Word("apple"));
  tree.insert(Word("banana"));
  tree.insert(Word("cherry"));
}*/

TEST_CASE ("BSTree<int> constructor") {
  BSTree<int> tree;

  CHECK(tree.getNumNodes() == 0);

  tree.insert(-1);
  CHECK(tree.getNumNodes() == 1);
}

TEST_CASE ("BSTree<string> constructor") {
  BSTree<string> tree;

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
  tree.printReverseOrder();

  //CHECK(tree.find("apple") == true);
  //CHECK(tree.find("grape") == false);
}

TEST_CASE ("Word constructor") {
  Word word;

  CHECK(word.getWord() == "");
  CHECK(word.getCount() == 0);
}

