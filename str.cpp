#include "data_structure.h"

// 409.Longest Palindrome
int Str::longestPalindrome(string s) {
  int A = 0, a = 0;
  int ans = 0;
  for (char ch : s) {
    if (ch >= 'a' && ch <= 'z') {
      if (a >> (ch - 'a') & 1) {
        ans += 2;
      }
      a ^= 1 << (ch - 'a');
    } else {
      if (A >> (ch - 'A') & 1) {
        ans += 2;
      }
      A ^= 1 << (ch - 'A');
    }
  }
  return A || a ? ans + 1 : ans;
}

// 5.Longest palindromic Substring (DP)
string Str::longestPalindromicSubstring(string s) {
  int n = s.size();
  if (n < 2)
    return s;
  int maxLen = 1, begin = 0;
  vector<vector<bool>> dp(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++) {
    dp[i][i] = false;
  }

  // 一定要从长度较短的字符串向长度较长的字符串进行转移
  for (int L = 2; L <= n; L++) {
    for (int i = 0; i < n; i++) {
      int j = i + L - 1;
      if (j >= n)
        break;

      if (s[i] != s[j]) {
        dp[i][j] = false;
      } else {
        if (j - i < 3)
          dp[i][j] = true;
        else
          dp[i][j] = dp[i + 1][j - 1];

        if (dp[i][j] && j - i + 1 > maxLen) {
          maxLen = j - i + 1;
          begin = i;
        }
      }
    }
  }

  return s.substr(begin, maxLen);
}
