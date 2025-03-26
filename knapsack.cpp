#include "data_structure.h"

/** 背包问题
  * 1. 0-1背包问题
  * 2. 完全背包问题
  * 3. 多重背包问题
  * 4. 分组背包问题
  */

/** 0-1背包问题
  * Time complexity: O(N * V)
  */
int knapsack01(const vector<int> &weight, const vector<int> &value, int V) {
  int N = weight.size(); 
  vector<vector<int>> dp(N + 1, vector<int>(V + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = weight[i - 1]; j <= V; j++) {
      // 只考虑第i件物品的策略 (放或不放)
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
    }
  }
  return dp[N][V];
}

/** 完全背包问题
  * Time complexity: O(N * V)
  */
int knapsackComplete(const vector<int> &weight, const vector<int> &value, int V) {}
