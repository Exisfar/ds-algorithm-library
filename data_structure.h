#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

class BinTreeNode {
public:
  int val;
  BinTreeNode *left;
  BinTreeNode *right;
  BinTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  bool search(int x);
  bool insert(int x);
  bool remove(int x);

  static vector<int> preorder(BinTreeNode *root);
  static vector<int> inorder(BinTreeNode *root);
  static vector<int> postorder(BinTreeNode *root);
  static vector<vector<int>> levelorder(BinTreeNode *root);
  static int maxDepth(BinTreeNode *root);
  static int minDepth(BinTreeNode *root);
  static BinTreeNode *invertTree(BinTreeNode *root);
  static bool isSymmetric(BinTreeNode *root);
  static int diameterOfBinaryTree(BinTreeNode *root);
  static BinTreeNode *sortedArrayToBST(vector<int> &nums);
  static bool isBalanced(BinTreeNode *root);
  static BinTreeNode *sortedListToBST(ListNode *head);
  static BinTreeNode *lowestCommonAncestor(BinTreeNode *root, BinTreeNode *p,
                                           BinTreeNode *q);
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

class Array {
public:
  vector<int> nums;

  static int firstMissingPositive(vector<int> &nums);
  static int findRepeatNumber(vector<int> &nums);
};