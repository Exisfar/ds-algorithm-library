#include "data_structure.h"

using namespace std;

// Given an array nums of distinct integers, return all the possible
// permutations. You can return the answer in any order.
void permuteHelper(vector<int> &nums, vector<int> &cur, vector<bool> &visited,
                   vector<vector<int>> &res, int n, int depth) {
  if (depth == n) {
    res.push_back(cur);
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      cur.push_back(nums[i]);
      permuteHelper(nums, cur, visited, res, n, depth + 1);
      cur.pop_back();
      visited[i] = false;
    }
  }
}

vector<vector<int>> permute(vector<int> &nums) {
  int n = nums.size();
  vector<vector<int>> res;
  vector<int> cur;
  vector<bool> visited(nums.size(), false);
  permuteHelper(nums, cur, visited, res, n, 0);
  return res;
}

void permuteHelper2(vector<vector<int>> &res, vector<int> &output, int first,
                    int len) {
  // 所有数都填完了
  if (first == len) {
    res.emplace_back(output);
    return;
  }
  for (int i = first; i < len; ++i) {
    // 动态维护数组
    swap(output[i], output[first]);
    // 继续递归填下一个数
    permuteHelper2(res, output, first + 1, len);
    // 撤销操作
    swap(output[i], output[first]);
  }
}
vector<vector<int>> permute2(vector<int> &nums) {
  vector<vector<int>> res;
  permuteHelper2(res, nums, 0, (int)nums.size());
  return res;
};

// Given an integer array nums of unique elements,
// return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the
// solution in any order.
// Solution: 每个数字都有两种状态，选或者不选，可以用mask或者递归
vector<vector<int>> Subsets(vector<int> &nums) {
  vector<int> t;
  vector<vector<int>> res;
  int n = nums.size();

  for (int mask = 0; mask < (1 << n); mask++) {
    t.clear();
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        t.push_back(nums[i]);
      }
    }
    res.push_back(t);
  }

  return res;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = permute(nums);
  for (auto &v : res) {
    for (auto &i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
