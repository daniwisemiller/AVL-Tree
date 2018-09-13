struct BinaryNode {
  BinaryNode(const int k) : 
    key(k), 
    height(1), balance(0),
    left(NULL), right(NULL) {}

  ~BinaryNode() {
    delete left;
    delete right;
    left = right = NULL;
  }

  int key;
  int height;
  int balance;
  BinaryNode *left;
  BinaryNode *right;

};

class BinaryTree {

public:
  BinaryTree() : root_(NULL) {}
  ~BinaryTree() { 
    delete root_;
  }

  void insert(const int value);
  void remove(const int value);

  void print_keys() const;
  void print_heights() const;

private:

  BinaryNode* insert_helper(const int key, BinaryNode* node);
  BinaryNode* remove_helper(const int key, BinaryNode* node);

  void print_keys_helper(BinaryNode* node) const;
  void print_heights_helper(BinaryNode* node) const;

  BinaryNode* rotate(BinaryNode* node);
  BinaryNode* rotate_left(BinaryNode* node);
  BinaryNode* rotate_right(BinaryNode* node);

  void update(BinaryNode* node);

  BinaryNode* root_;
};
