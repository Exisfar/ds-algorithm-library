// https://www.luogu.com.cn/problem/P2056
// 
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q, a, b;
  cin >> N;
  vector<vector<int>> g(N + 1);
  vector<int> dis(N + 1);
  vector<int> closed(N + 1, false);

  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  cin >> Q;
  char choice, n;
  while (Q--) {
    cin >> choice;
    if (choice == 'C') { // change
      cin >> n;
      closed[n] = !closed[n];
    } else { // game
    }
  }
  return 0;
}