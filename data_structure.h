#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}

  static bool hasCycle(ListNode *head);
  static int getMiddle(ListNode *head);
  // Intersection of Two Linked Lists
  static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
  // Reverse Linked List
  static ListNode *reverseList(ListNode *head);
  // Palindrome Linked List
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  static void preorder(TreeNode *root);
  static void inorder(TreeNode *root);
  static void postorder(TreeNode *root);
  static void levelorder(TreeNode *root);
  static int maxDepth(TreeNode *root);
  static int minDepth(TreeNode *root);
  static bool isSymmetric(TreeNode *root);
  static bool isBalanced(TreeNode *root);
  static TreeNode *sortedArrayToBST(std::vector<int> &nums);
  static TreeNode *sortedListToBST(ListNode *head);
  static TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
};

struct Trie {
  std::vector<Trie *> children;
  bool is_end;

  Trie() : children(26), is_end(false) {}

  void insert(std::string word);
  bool search(std::string word);
  bool startsWith(std::string prefix);
};