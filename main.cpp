#include <iostream>
#include "binary_tree.h"
using namespace std;

int main(int argc, char** argv) {

  BinaryTree tree;

  char option; // Menu option
  int key; // Key for insert and remove

  do {
    cin >> option;
    switch(option) {
      case 'i':
        cin >> key;
        tree.insert(key);
        break;
      case 'r':
        cin >> key;
        tree.remove(key);
        break;
      case 'p':
        tree.print_keys();
        break;
      case 'h':
        tree.print_heights();
        break;
      default:
        break;
    }
  } while(option != 'q');
}
