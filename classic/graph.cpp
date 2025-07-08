#include "data_structure.h"

// there is a cycle only if we can reach a node that's already in the path
static bool isCycleUtilDirectedGraph(vector<vector<int>> &adj, int u,
                                     vector<bool> &visited,
                                     vector<bool> &path) {
  visited[u] = true;
  path[u] = true;

  for (int x : adj[u]) {
    if (!visited[x] && isCycleUtilDirectedGraph(adj, x, visited,
                                                path)) { // prevent early return
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
bool Graph::isCycleDirectedGraph(vector<vector<int>> &adj) {
  int V = adj.size();
  vector<bool> visited(V, false);
  vector<bool> path(V, false);

  for (int i = 0; i < V; i++) {
    if (!visited[i] && isCycleUtilDirectedGraph(adj, i, visited, path))
      return true;
  }

  return false;
}

/** Detect cycle in an Undirected Graph
 * Method: DFS
 * Complexity: O(V+E), O(V)
 */
static bool isCycleUtilUndirectedGraph(vector<vector<int>> &adj, int u,
                                       vector<bool> &visited,
                                       vector<bool> &path, int parent) {
  visited[u] = true;
  path[u] = true;

  for (int x : adj[u]) {
    if (!visited[x] && isCycleUtilUndirectedGraph(adj, x, visited, path, u))
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

bool Graph::isCycleUndirectedGraph(vector<vector<int>> &adj) {
  int V = adj.size();
  vector<bool> visited(V, false);
  vector<bool> path(V, false);

  // call the resursive helper function to
  // detect cycle in different DFS trees
  for (int i = 0; i < V; i++) {
    if (!visited[i] && isCycleUtilUndirectedGraph(adj, i, visited, path, -1))
      return true;
  }

  return false;
}

/** Unweighted Shortest Path
 * Method: BFS
 * Complexity: O(V+E), O(V)
 */
void Graph::unweightedShortestPath(Vertex *s) {
  queue<Vertex *> q;

  for (Vertex *v : vertices) {
    v->dist = 0x7fffffff; // initialize distance to infinity
  }

  s->dist = 0;
  q.push(s);

  while (!q.empty()) {
    Vertex *u = q.front();
    q.pop();
    for (Edge *e : u->adj) {
      if (e->v->dist == 0x7fffffff) { // if v is not visited
        e->v->dist = u->dist + 1;     // update distance
        q.push(e->v);                 // push to queue
      }
    }
  }
}

/** Dijkstra's Algorithm
 * Method: Greedy
 * Complexity: O(E + VlogV), O(V)
 * Note: Dijkstra's algorithm is not suitable for graphs with negative weight
 * edges. For graphs with negative weight edges, Bellman-Ford algorithm is a
 * better choice.
 */
void Graph::dijkstra(vector<vector<int>> edges, int n, int s) {
  vector<vector<pair<int, int>>> g(n); // adjacency list
  vector<int> dis(n, 0x7fffffff);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  for (auto &edge : edges) {
    g[edge[0] - 1].emplace_back(edge[1] - 1, edge[2]);
  }
  dis[s - 1] = 0;
  pq.emplace(0, s - 1);

  while (!pq.empty()) {
    auto [dis_x, x] = pq.top();
    pq.pop();

    if (dis_x > dis[x])
      continue;

    for (auto &[y, d] : g[x]) {
      // relax x's neighbors
      int dis_y = dis_x + d;
      if (dis_y < dis[y]) {
        dis[y] = dis_y;
        pq.emplace(dis_y, y);
      }
    }
  }
}

/**
 * Print shortest path to v after dijkstra has run.
 * Assume that the path exists.
 */
void Graph::printPath(Vertex *v) {
  if (v->path != nullptr) {
    printPath(v->path);
    cout << " -> ";
  }
  cout << v->id;
}

/** kruskal Algorithm
 * Method: Greedy
 * Complexity: O(ElogE), O(V)
 * Note: Kruskal's algorithm is a greedy algorithm that finds a minimum spanning
 * tree for a connected weighted graph. It finds an edge of the least possible
 * weight that connects any two trees in the forest.
 */
void Graph::kruskal() {
  int tot = 0;
  int cost = 0;
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
