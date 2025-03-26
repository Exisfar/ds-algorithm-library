#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;


class ListNode {
public:
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

class TreeNode {
public:
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
  static TreeNode *sortedArrayToBST(vector<int> &nums);
  static TreeNode *sortedListToBST(ListNode *head);
  static TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p,
                                        TreeNode *q);
};

class Graph {
public:
  vector<vector<int>> &adj; // adjacency list

  // Detect Cycle in a Directed Graph (DFS)
  bool isCycleUtilDirectedGraph(int u, vector<bool> &visited,
                                vector<bool> &path);
  bool isCycleDirectedGraph();
  // Detect Cycle in an Undirected Graph (DFS)
  bool isCycleUtilUndirectedGraph(int u, vector<bool> &visited,
                                  vector<bool> &path, int parent);
  bool isCycleUndirectedGraph();

  // Topological Sort (BFS)
  bool hasTopoOrdering(int numCourses);
};

class Trie {
public:
  vector<Trie *> children;
  bool is_end;

  Trie() : children(26), is_end(false) {}

  void insert(string word);
  bool search(string word);
  bool startsWith(string prefix);
};

class hashTable {
public:
};

class Matrix {
public:
  vector<vector<int>> &matrix;

  void setZeroes();
  vector<int> spiralOrder();
  void rotate();
};

class Str {
public:
  string s;

  static int longestPalindrome(string s);
  // 5.Longest palindromic Substring (DP)
  static string longestPalindromicSubstring(string s);
};
