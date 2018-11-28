#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "bstree.hpp"

TEST_CASE ("BSTree constructor") {
  BSTree tree;

  CHECK(tree.toString()) == "";
  CHECK(tree.getNumNodes()) == 0;
}
