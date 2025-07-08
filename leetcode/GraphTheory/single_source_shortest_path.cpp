#include "../leetcode.h"

int SingleSourceShortestPath::networkDelayTime(vector<vector<int>> &times,
                                               int n, int k) {
  vector<int> dis(n, 0x7fffffff);
  vector<vector<pair<int, int>>> g(n); // 邻接表
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  for (auto &t : times) {
    g[t[0] - 1].emplace_back(t[1] - 1, t[2]);
  }

  dis[k - 1] = 0;
  pq.emplace(0, k - 1);

  while (!pq.empty()) {
    auto [dis_x, x] = pq.top();
    pq.pop();
    if (dis_x > dis[x])
      continue;

    for (auto &[y, d] : g[x]) {
      int dis_y = dis_x + d;
      if (dis_y < dis[y]) {
        dis[y] = dis_y;
        pq.emplace(dis_y, y);
      }
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, dis[i]);
  }
  return res < 0x7fffffff ? res : -1;
}