#include "data_structure.h"

/** Maximum Product Subarray
 * @brief Given an integer array nums, find a contiguous non-empty subarray
 within the array (containing at least one number) which has the largest
 product, and return that product.
 * It is guaranteed that the answer will fit in a 32-bit integer.
 * @note: f_max[i] = max(f_max[i-1] * nums[i], nums[i]) is wrong
 */
int DP::maxProduct(vector<int> &nums) {
  int n = nums.size();
  int res = nums[0];
  int f_max[n], f_min[n];

  f_max[0] = nums[0];
  f_min[0] = nums[0];

  for (int i = 1; i < n; i++) {
    f_max[i] =
        max(max(f_max[i - 1] * nums[i], f_min[i - 1] * nums[i]), nums[i]);
    f_min[i] =
        min(min(f_max[i - 1] * nums[i], f_min[i - 1] * nums[i]), nums[i]);
    res = max(res, f_max[i]);
  }
  return res;
}

/** Partition Equal Subset Sum
 * @brief Given a non-empty array nums containing only positive integers,
 * find if the array can be partitioned into two subsets such that the sum
 * of elements in both subsets is equal.
 * @note: f[i][j] = f[i-1][j] || f[i-1][j-nums[i]], j >= nums[i]
 *                = f[i-1][j], j < nums[i]
 */
bool canPartition(vector<int> &nums) {
  int n = nums.size();
  if (n < 2)
    return false;
  int sum = 0;
  int max_num = 0;
  for (int num : nums) {
    sum += num;
    max_num = max(max_num, num);
  }
  if (sum % 2 != 0)
    return false;
  int target = sum / 2;
  if (max_num > target)
    return false;

  vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
  for (int i = 0; i <= n; i++)
    dp[i][0] = true;
  dp[1][nums[0]] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum / 2; j++) {
      if (j < nums[i - 1])
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
    }
  }
  return dp[n][target];
}

/** Longest Common Subsequence
 * @brief Given two strings text1 and text2, return the length of their longest
 * common subsequence. If there is no common subsequence, return 0.
 * A subsequence of a string is a new string that is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (i.e., "ace" is a
 * subsequence of "abcde" while "aec" is not). A common subsequence of two
 * strings is a subsequence that is common to both strings.
 * @note: f[i][j] = f[i-1][j-1] + 1 if text1[i - 1] == text2[j - 1]
 *                = max(f[i-1][j], f[i][j-1]) else
 *                = 0 if i == 0 or j == 0
 */
int DP::longestCommonSubsequence(string text1, string text2) {
  int m = text1.size(), n = text2.size();
  vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (text1[i - 1] == text2[j - 1])
        f[i][j] = f[i - 1][j - 1] + 1;
      else
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    }
  }
  return f[m][n];
}

// 区间DP：从小区间转移到大区间
int DP::longestPalindromeSubseq(string s) { // 这题也可以将s反转后求LCS
  int n = s.size();
  int f[n + 1][n + 1];

  for (int i = n; i >= 1; i++) {
    f[i][i] = 1;
    for (int j = 1; j < i; j++) {
      if (s[i] == s[j])
        f[i][j] = f[i + 1][j - 1] + 2;
      else
        f[i][j] = max(f[i + 1][j], f[i][j - 1]);
    }
  }

  return f[1][n];
}