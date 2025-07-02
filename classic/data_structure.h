#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <cstring>


using namespace std;

class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}

  bool hasCycle(ListNode *head);
  int getMiddle(ListNode *head);
  // Intersection of Two Linked Lists
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
  // Reverse Linked List
  ListNode *reverseList(ListNode *head);
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

  vector<int> preorder(BinTreeNode *root);
  vector<int> inorder(BinTreeNode *root);
  vector<int> postorder(BinTreeNode *root);
  vector<vector<int>> levelorder(BinTreeNode *root);
  int maxDepth(BinTreeNode *root);
  int minDepth(BinTreeNode *root);
  BinTreeNode *invertTree(BinTreeNode *root);
  bool isSymmetric(BinTreeNode *root);
  int diameterOfBinaryTree(BinTreeNode *root);
  BinTreeNode *sortedArrayToBST(vector<int> &nums);
  bool isBalanced(BinTreeNode *root);
  BinTreeNode *sortedListToBST(ListNode *head);
  BinTreeNode *lowestCommonAncestor(BinTreeNode *root, BinTreeNode *p,
                                           BinTreeNode *q);
};

struct Vertex;

struct Edge {
  Vertex *v;
  int cost;
};

struct Vertex {
  int id;
  vector<Edge *> adj; // adjacent list of vertices
  bool known;
  int dist;     // distance from source
  Vertex *path; // previous vertex in the path

  bool operator>(const Vertex &other) const { return dist > other.dist; }
};

class Graph {
public:
  /** Methods to represent a graph
   * 1. Adjacency Matrix
   * 2. Adjacency List
   * 3. Edge List
   */
  vector<Vertex *> vertices; // list of vertices

  // Detect Cycle in a Directed Graph (DFS)
  bool isCycleDirectedGraph(vector<vector<int>> &adj);
  // Detect Cycle in an Undirected Graph (DFS)
  bool isCycleUndirectedGraph(vector<vector<int>> &adj);
  void printPath(Vertex *v);
  void unweightedShortestPath(Vertex *s);
  // shortest path from source to all vertices
  void dijkstra(vector<vector<int>> weights, int n, int s);
  // Minimum Spanning Tree (MST)
  void kruskal();
  void prim();
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

  int longestPalindrome(string s);
  // 5.Longest palindromic Substring (DP)
  string longestPalindromicSubstring(string s);
};

class Array {
public:
  vector<int> nums;

  int firstMissingPositive(vector<int> &nums);
  int findRepeatNumber(vector<int> &nums);
};

class Stack {
public:
  int longestValidParentheses(string s);
};

class Sorting {
public:
  void mergeSort(int *a, int left, int right);
  void quickSort(int *a, int left, int right);
};

class DP {
public:
  int maxProduct(vector<int> &nums);
  bool canPartition(vector<int> &nums);
  int longestCommonSubsequence(string text1, string text2);
};

class Backtrack {
public:
  vector<vector<int>> permute(vector<int> &nums);
  vector<vector<int>> permute2(vector<int> &nums);
  vector<vector<int>> Subsets(vector<int> &nums);
};

class Uncategorized {
public:
  int kthLargest(vector<int> &nums, int k);
};