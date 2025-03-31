#include "data_structure.h"


int main() {
  BinTreeNode * root = new BinTreeNode(1);
  root->left = new BinTreeNode(2);
  root->right = new BinTreeNode(3);
  root->left->left = new BinTreeNode(4);
  root->left->right = new BinTreeNode(5);
  cout << BinTreeNode::diameterOfBinaryTree(root) << "\n";
  return 0;
}