#include <iostream>
#include "binary_tree.h"
using namespace std;

//******* INSERT
void BinaryTree::insert(const int key) {

  if (root_ == NULL) {
    root_ = new BinaryNode(key);
    return;
  }

  root_ = insert_helper(key, root_);
}

BinaryNode* BinaryTree::insert_helper(const int key, BinaryNode* node) {

  //** Move left 
  if(key < node->key) {
    if(node->left == NULL) {
      node->left = new BinaryNode(key); 
    } 
    else {
      node->left = insert_helper(key, node->left);
    }
  }
  //** Move right
  else {
    if(node->right == NULL) {
      node->right = new BinaryNode(key); 
    } 
    else {
      node->right = insert_helper(key, node->right);
    }
  }

  update(node);
  return rotate(node);
}

//******** REMOVE
void BinaryTree::remove(const int key) {
  root_ = remove_helper(key, root_);
}

BinaryNode* BinaryTree::remove_helper(const int key, BinaryNode* node) {
  if (node == NULL) {
    cout << "Error" << endl;
    return NULL;
  }

  if (key < node->key) {
    node->left = remove_helper(key, node->left);
  }
  else if (key > node->key) {
    node->right = remove_helper(key, node->right);
  }
  else {
    BinaryNode* node_remove = node;
    if (node_remove->left && node_remove->right) {
      node_remove = node_remove->left;
      while (node_remove->right) {
        node_remove = node_remove->right;
      }
      node->key = node_remove->key;
      node->left = remove_helper(node->key, node->left);
    }
    else {
      if (node_remove->left && !node_remove->right)
        node = node_remove->left;
      else if (!node_remove->left && node_remove->right)
        node = node_remove->right;
      else
        node = NULL;

      node_remove->left = NULL;
      node_remove->right = NULL;
      delete node_remove;
    }
  }

  update(node);
  return rotate(node);
}


void BinaryTree::update(BinaryNode* node) {
  if (node == NULL)
    return;

  if (node->right && node->left) {
    node->height = max(node->right->height, node->left->height) + 1;
    node->balance = node->right->height - node->left->height;
  }
  else if (node->right && !node->left) {
    node->height = node->right->height + 1;
    node->balance = node->right->height;
  }
  else if (!node->right && node->left) {
    node->height =  node->left->height + 1;
    node->balance = -node->left->height;
  }
  else {
    node->height = 1;
    node->balance = 0;
  }
}

//********** ROTATE
BinaryNode* BinaryTree::rotate(BinaryNode* node) {
  if (node == NULL)
    return NULL;

  if (node->balance == 2) {
    if (node->right->balance >= 0) {
      return rotate_left(node);
    } 
    else {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    }
  }
  else if (node->balance == -2) {
    if (node->left->balance <= 0) {
      return rotate_right(node);
    } 
    else {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }
  }

  return node;
}

BinaryNode* BinaryTree::rotate_left(BinaryNode* node) {
  BinaryNode* swap = node->right;
  node->right = swap->left;
  swap->left = node;

  update(node);
  update(swap);

  return swap;
}

BinaryNode* BinaryTree::rotate_right(BinaryNode* node) {
  BinaryNode* swap = node->left;
  node->left = swap->right;
  swap->right = node;

  update(node);
  update(swap);

  return swap;
}


//********** PRINT
void BinaryTree::print_keys() const {

  if (root_ == NULL) {
    cout << "Empty" << endl;
    return;
  }

  print_keys_helper(root_);
  cout << endl;
}

void BinaryTree::print_keys_helper(BinaryNode* node) const {
  if (node == NULL)
    return;

  print_keys_helper(node->left);
  cout << node->key << " ";
  print_keys_helper(node->right);
}

void BinaryTree::print_heights() const {
  if (root_ == NULL) {
    cout << "Empty" << endl;
    return;
  }

  print_heights_helper(root_);
  cout << endl;
}

void BinaryTree::print_heights_helper(BinaryNode* node) const {
  if (node == NULL)
    return;

  print_heights_helper(node->left);
  cout << node->height << " ";
  print_heights_helper(node->right);
}
