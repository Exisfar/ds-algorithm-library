#include "data_structure.h"
#include <stack>

vector<int> BinTreeNode::preorder(BinTreeNode *root) {
  vector<int> res;
  stack<BinTreeNode *> st;

  // root may be null during the traversal
  while (root || !st.empty()) {
    while (root) {
      st.push(root);
      res.push_back(root->val);
      root = root->left;
    }
    root = st.top();
    st.pop();
    root = root->right;
  }

  return res;
}

vector<int> BinTreeNode::inorder(BinTreeNode *root) {
  vector<int> res;
  stack<BinTreeNode *> st;

  while (root || !st.empty()) {
    while (root) {
      st.push(root);
      root = root->left;
    }
    root = st.top();
    st.pop();
    res.push_back(root->val);
    root = root->right;
  }

  return res;
}

/** levelOrder (BFS)
 * @brief: Perform level order traversal of a binary tree.
 * @param root: The root of the binary tree.
 * @return: A vector of vectors, where each inner vector represents a level
 *          of the binary tree.
 * @note: The level order traversal visits nodes level by level, from left to
 *        right.
 * Time Complexity: O(n). Each node is visited once.
 */
vector<vector<int>> BinTreeNode::levelorder(BinTreeNode *root) {
  vector<vector<int>> res;
  if (root == nullptr)
    return res;
  queue<BinTreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++) {
      BinTreeNode *node = q.front();
      q.pop();
      level.push_back(node->val);
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    res.push_back(level);
  }
  return res;
}

/** maxDepth (BFS)
 * @brief: Find the maximum depth of a binary tree.
 * @param root: The root of the binary tree.
 * @return: The maximum depth of the binary tree.
 * @note: The maximum depth is the number of nodes along the longest path
 *        from the root node down to the farthest leaf node.
 *        A leaf is a node with no children.
 *        The depth of the root node is 1.
 *        The depth of an empty tree is 0.
 * Time Complexity: O(n). Each node is visited once.
 * Space Complexity: O(n). The space complexity is determined by the queue
 */

int BinTreeNode::maxDepth(BinTreeNode *root) {
  if (!root)
    return 0;
  queue<BinTreeNode *> q;
  q.push(root);
  int res = 0;

  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      BinTreeNode *node = q.front();
      q.pop();
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    res++;
  }
  return res;

  // Alternative solution using DFS
  // if (!root) return 0;
  // return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

/** minDepth (BFS)
 * @brief: Find the minimum depth of a binary tree.
 * @param root: The root of the binary tree.
 * @return: The minimum depth of the binary tree.
 * @note: The minimum depth is the number of nodes along the shortest path
 *        from the root node down to the nearest leaf node.
 *        A leaf is a node with no children.
 *        The depth of the root node is 1.
 *        The depth of an empty tree is 0.
 * Time Complexity: O(n). Each node is visited once.
 * Space Complexity: O(n). The space complexity is determined by the queue.
 */
int BinTreeNode::minDepth(BinTreeNode *root) {
  if (root == nullptr)
    return 0;
  if (root->left == nullptr && root->right == nullptr)
    return 1;
  queue<BinTreeNode *> q;
  q.push(root);
  int res = 0;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      BinTreeNode *node = q.front();
      q.pop();
      if (node->left == nullptr && node->right == nullptr) {
        return res + 1;
      }
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    res++;
  }
  return res;

  // Alternative solution using DFS
  // if (!root) return 0;
  // if (root->left == nullptr && root->right == nullptr) return 1;
  // int res = INT_MAX;
  // if (root->left) res = min(res, minDepth(root->left));
  // if (root->right) res = min(res, minDepth(root->right));
  // return res + 1;
}

/** invertTree
 * Time Complexity: O(n)
 * Splace Complexity: O(height)
 */
BinTreeNode *BinTreeNode::invertTree(BinTreeNode *root) {
  if (root == nullptr)
    return nullptr;
  // invert first and then swap
  BinTreeNode *left = invertTree(root->left);
  BinTreeNode *right = invertTree(root->right);
  root->left = right;
  root->right = left;
  return root;
}

/** isSymmetric
 * @brief: Check if a binary tree is symmetric.
 * @param root: The root of the binary tree.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
bool BinTreeNode::isSymmetric(BinTreeNode *root) {
  if (root == nullptr)
    return true;
  queue<BinTreeNode *> q;
  q.push(root->left);
  q.push(root->right);
  while (!q.empty()) {
    BinTreeNode *left = q.front();
    q.pop();
    BinTreeNode *right = q.front();
    q.pop();
    if (left == nullptr && right == nullptr)
      continue;
    else if (left == nullptr || right == nullptr)
      return false;
    else if (left->val != right->val)
      return false;
    q.push(left->left);
    q.push(right->right);
    q.push(left->right);
    q.push(right->left);
  }
  return true;
}

/** diameterOfBinaryTree
 * @brief: Find the diameter of a binary tree.
 * @note: The diameter is the length of the longest path between any two nodes
 *        in a tree. This path may or *may not pass through the root*.
 *        The length of a path between two nodes is represented by the number
 *        of edges between them.
 * Time Complexity: O(n). Each node is visited once.
 * Space Complexity: O(height). The space complexity is determined by the
 *                  recursion stack.
 */
static int max_diameter = 0;
static int maxDepthForDiameter(BinTreeNode *root) {
  if (root == nullptr)
    return 0;

  int left_max_depth = maxDepthForDiameter(root->left);
  int right_max_depth = maxDepthForDiameter(root->right);
  max_diameter = max(max_diameter, left_max_depth + right_max_depth);
  return max(left_max_depth, right_max_depth) + 1;
}

int BinTreeNode::diameterOfBinaryTree(BinTreeNode *root) {
  // Record the maximum diameter during the recursion
  maxDepthForDiameter(root);
  return max_diameter;
}
