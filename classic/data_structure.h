#include <bits/stdc++.h>

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

class Tree {
public:
  // 注意：树的直径问题仅适用于​​无向无环连通图​​（即树结构），不适用于有向图或带权图（需其他算法如Floyd-Warshall）。
  class Node {
    int x;
    vector<int> children;
  };

  int DFSforDiameter(Node *node, Node *parent);
  int diameter();
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
  // 线性DP：一般在前缀/后缀上转移
  // 区间DP：从小区间转移到大区间
  int longestPalindromeSubseq(string s);
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

class SegmentTree {
public:
  vector<int> a;   // input array
  vector<int> seg; // 假设存储每个区间的最大值

  SegmentTree(vector<int> &a) {
    a = a;
    int n = a.size();
    seg.resize(n * 4, 0);
    build(0, n - 1, 1);
  }

  // 递归建树
  // 对 [l, r] 区间建立线段树,当前根的编号为 p
  void build(int p, int l, int r) {
    if (l == r) {
      seg[p] = a[l];
      return;
    }
    int m = l + ((r - l) >> 1);
    build(p * 2, l, m);
    build(p * 2 + 1, m + 1, r);
    seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
  }

  // 单点更新
  void update(int p, int l, int r, int i, int x) {
    if (l == r) {
      seg[p] = x;
      return;
    }
    int m = l + ((r - l) >> 1);
    if (i <= m) {
      update(p * 2, l, m, i, x);
    } else {
      update(p * 2 + 1, m + 1, r, i, x);
    }
    seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
  }

  // 区间查询
  // 找区间[l,r]内的第一个>=x的数，返回这个数的下标，没找到就返回-1
  int findFirst(int p, int l, int r, int x) {
    if (seg[p] < x) { // 区间没有>=x的数字
      return -1;
    }
    if (l == r) {
      return l;
    }
    int m = l + ((r - l) >> 1);
    int i = findFirst(p * 2, l, m, x);       // 递归左子树
    if (i < 0) {                             // 左子树没找到
      i = findFirst(p * 2 + 1, m + 1, r, x); // 递归右子树
    }
    return i;
  }
};