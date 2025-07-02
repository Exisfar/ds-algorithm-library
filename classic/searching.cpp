#include "data_structure.h"

// [二分查找为什么总是写错？](https://www.bilibili.com/video/BV1d54y1q7k7/?share_source=copy_web&vd_source=1bf79132ed79a1a3701cb6da3a16e857)
int binary_search(vector<int> nums, int target) {
  int l = -1, r = nums.size();
  while (l + 1 < r) { 
    int m = l + (r - l) / 2; // 避免潜在的溢出问题
    if (nums[m] == target)
      return m;
    else if (nums[m] < target) // l 最终指向最后一个小于 target 的元素，r 最终指向第一个大于等于 target 的元素
      l = m;
    else
      r = m;
  }

  return nums[r] == target ? r : -1;
}
