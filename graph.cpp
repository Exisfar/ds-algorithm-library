#include "data_structure.h"

// there is a cycle only if we can reach a node that's already in the path
bool Graph::isCycleUtilDirectedGraph(int u, vector<bool> &visited,
                                     vector<bool> &path) {
  visited[u] = true;
  path[u] = true;

  for (int x : adj[u]) {
    if (!visited[x] &&
        isCycleUtilDirectedGraph(x, visited, path)) { // prevent early return
      return true;
    }
    return path[x];
  }

  path[u] = false;
  return false;
  // no need to empty the `visited` because if we start from another node,
  // we've comfirmed that there's no cycle starting from it.
}

/** Detect Cycle in a Directed Graph
  * Method: DFS
  * Complexity: O(V+E), O(V)
  */
bool Graph::isCycleDirectedGraph() {
  int V = adj.size();
  vector<bool> visited(V, false);
  vector<bool> path(V, false);

  for (int i = 0; i < V; i++) {
    if (!visited[i] && isCycleUtilDirectedGraph(i, visited, path))
      return true;
  }

  return false;
}

/** Detect cycle in an Undirected Graph
  * Method: DFS
  * Complexity: O(V+E), O(V)
  */
bool Graph::isCycleUtilUndirectedGraph(int u, vector<bool> &visited,
                                       vector<bool> &path, int parent) {
  visited[u] = true;
  path[u] = true;

  for (int x : adj[u]) {
    if (!visited[x] && isCycleUtilUndirectedGraph(x, visited, path, u))
      return true;
    // If an adjacent vertex is visited and
    // is not parent of current vertex,
    // then there exists a cycle in the graph.
    if (x != parent && path[x])
      return true;
  }

  path[u] = false;
  return false;
}

bool Graph::isCycleUndirectedGraph() {
  int V = adj.size();
  vector<bool> visited(V, false);
  vector<bool> path(V, false);

  // call the resursive helper function to
  // detect cycle in different DFS trees
  for (int i = 0; i < V; i++) {
    if (!visited[i] && isCycleUtilUndirectedGraph(i, visited, path))
      return true;
  }

  return false;
}

/** Topological Sort
  * Method: BFS
  * Complexity: O(V+E), O(V)
  */

// vector<vector<int>> edges;
// vector<int> indeg;
// vector<int> topo_order;

// bool hasTopoOrdering(int numCourses, vector<vector<int>>& prerequisites) {
// edges.resize(numCourses);
// indeg.resize(numCourses);
//
// for (const auto &info : prerequisites) {
// edges[info[1]].push_back(info[0]);
// ++indeg[info[0]];
// }
//
// queue<int> q;
//
// for (int i = 0; i < numCourses; i++)
// if (!indeg[i])
// q.push(i);
//
// int visited = 0;
// while (!q.empty()) {
// ++visited;
// int u = q.front();
// q.pop();
// for (int v : edges[u]) {
// --indeg[v];
// if (!indeg[v])
// q.push(v);
// }
// }
//
// return visited == numCourses;
// }

// Union-find Algorithm
// [Union-find
// Algorithm](https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/)

