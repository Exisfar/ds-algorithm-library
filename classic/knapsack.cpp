#include "data_structure.h"

/** 背包问题
 * 1. 0-1背包问题
 * 2. 完全背包问题
 * 3. 多重背包问题
 * 4. 分组背包问题
 */

/** 0-1背包问题
 * Time complexity: O(N * V)
 * 物品只能选1次，所以必须从dp[i-1][...]转移
 */
int knapsack01(const vector<int> &weight, const vector<int> &value, int V) {
  int N = weight.size();
  vector<vector<int>> dp(N, vector<int>(V + 1, 0));

  for (int i = 0; i <= V; i++) {
    if (i >= weight[0])
      dp[0][i] = value[0];
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= V; j++) {
      if (j < weight[i - 1])
        // 不能放第i件物品
        dp[i][j] = dp[i - 1][j];
      else
        // 只考虑第i件物品的策略 (放或不放)
        dp[i][j] =
            max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
    }
  }
  return dp[N - 1][V];
}

/** 完全背包问题
 * Time complexity: O(N * V)
 * 物品可以选多次，所以可以从dp[i][...]转移
 */
int knapsackComplete(const vector<int> &weight, const vector<int> &value,
                     int V) {
  int N = weight.size();
  vector<vector<int>> dp(N, vector<int>(V + 1, 0));
  for (int i = 0; i <= V; i++) {
    if (i >= weight[0])
      dp[0][i] = (i / weight[0]) * value[0];
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= V; j++) {
      if (j < weight[i])
        dp[i][j] = dp[i - 1][j];
      else {
        // 不选第i件物品或选第i件物品1次、2次、...
        // dp[i][j - weight[i]] + value[i]已经覆盖了dp[i-1][j - weight[i]] +
        // value[i]的情况
        dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
      }
    }
  }
  return dp[N - 1][V];
}
