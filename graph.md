# Graph

## Detect Cycle in a Directed Graph

### DFS

- Complexity: O(V+E), O(V)

```cpp
bool isCycleUtil(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& path) {
  visited[u] = true;
  path[u] = true;

  for (int x : adj[u]) {
    if (!visited[x] && isCycleUtil(adj, x, visited, path))
      return true;
    if (path[x])
      return true;
  }

  path[u] = false;
  return false;
}

bool isCycle(vector<vector<int>>& adj) {
  int V = adj.size();
  vector<bool> visited(V, false);
  vector<bool> path(V, false);

  // call the resursive helper function to
  // detect cycle in different DFS trees
  for (int i = 0; i < V; i++) {
    if (!visited[i] && isCycleUtil(adj, i, visited, path))
      return true;
  }

  return false;
}
```

### Topological Sorting

- Complexity: O(V+E), O(V)

```cpp
coming soon.
```

### Union-find Algorithm

- [Union-find Algorithm](https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/)

## Detect cycle in an Undirected Graph

### DFS

- Complexity: O(V+E), O(V)

```cpp
bool isCycleUtil(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& path, int parent) {
  visited[u] = true;
  path[u] = true;

  for (int x : adj[u]) {
    if (!visited[x] && isCycleUtil(adj, x, visited, path, u))
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

bool isCycle(vector<vector<int>>& adj) {
  int V = adj.size();
  vector<bool> visited(V, false);
  vector<bool> path(V, false);

  // call the resursive helper function to
  // detect cycle in different DFS trees
  for (int i = 0; i < V; i++) {
    if (!visited[i] && isCycleUtil(adj, i, visited, path))
      return true;
  }

  return false;
}
```


## Topological Ordering

```cpp
vector<vector<int>> edges;
vector<int> indeg;
vector<int> topo_order;

bool hasTopoOrdering(int numCourses, vector<vector<int>>& prerequisites) {
  edges.resize(numCourses);
  indeg.resize(numCourses);

  for (const auto& info : prerequisites) {
    edges[info[1]].push_back(info[0]);
    ++indeg[info[0]];
  }

  queue<int> q;

  for (int i = 0; i < numCourses; i++)
    if (!indeg[i]) q.push(i);

  int visited = 0;
  while (!q.empty()) {
    ++visited;
    int u = q.front();
    q.pop();
    for (int v : edges[u]) {
      --indeg[v];
      if (!indeg[v]) q.push(v);
    }
  }

  return visited == numCourses;
}
```