#include "data_structure.h"

/** First missing positive
 * Given an unsorted integer array nums, find the smallest missing positive
 * integer. You must implement an algorithm that runs in O(n) time and uses O(1)
 * extra space. Method: 原地哈希，将数组视作一个哈希表，nums[i]的值应该在[1,
 * n]之间。 如果nums[i]的值在[1, n]之间且nums[i] !=
 * nums[nums[i]-1]，则交换nums[i]和nums[nums[i]-1] 直到nums[i]的值不在[1,
 * n]之间或者nums[i] == nums[nums[i]-1]。 Time complexity: O(n) Space
 * Time complexity: O(n) Space complexity: O(1)
 */
int Array::firstMissingPositive(vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
      swap(nums[i], nums[nums[i] - 1]);
    }
  }

  for (int i = 0; i < n; i++) {
    if (nums[i] != i + 1)
      return i + 1;
  }

  return n + 1;
}

/** Find repeat number
 * Given an array nums containing n integers where each integer is between 0
 * and n-1 (inclusive), find the duplicate one. You must not modify the array
 * nums. Time complexity: O(n) Space complexity: O(1)
 */
int Array::findRepeatNumber(vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    while (nums[i] != i) {
      if (nums[i] == nums[nums[i]]) {
        // return nums[i];
        cout << nums[i] << endl;
        break;
      }
      swap(nums[i], nums[nums[i]]);
    }
  }
  return -1;
}