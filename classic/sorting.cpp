#include "data_structure.h"

static int lomutoPartition(int *a, int left, int right) {
  int pivot = a[right];
  int i = left - 1;

  for (int j = left; j < right; j++) {
    if (a[j] <= pivot) {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[right]);
  return i + 1;
}

static int hoarePartition(int *a, int left, int right) {
  int pivot = a[left];
  int i = left - 1, j = right + 1;

  while (true) {
    // Find leftmost element greater than or
    // equal to pivot
    do {
      i++;
    } while (a[i] < pivot);

    // Find rightmost element smaller than
    // or equal to pivot
    do {
      j--;
    } while (a[j] > pivot);

    // If two pointers met.
    if (i >= j)
      return j;

    swap(a[i], a[j]);
  }
}

void Sorting::quickSort(int *a, int left, int right) {
  if (left >= right)
    return;
  int pivot_pos = hoarePartition(a, left, right);
  quickSort(a, left, pivot_pos - 1);
  quickSort(a, pivot_pos + 1, right);
}

void Sorting::mergeSort(int *a, int left, int right) {
  if (left >= right)
    return;
  int mid = (left + right) / 2;
  mergeSort(a, left, mid);
  mergeSort(a, mid + 1, right);
  int i = left, j = mid + 1;
  vector<int> tmp;
  while (i <= mid && j <= right) {
    if (a[i] < a[j])
      tmp.push_back(a[i++]);
    else
      tmp.push_back(a[j++]);
  }
  while (i <= mid)
    tmp.push_back(a[i++]);
  while (j <= right)
    tmp.push_back(a[j++]);
  for (int k = left; k <= right; k++)
    a[k] = tmp[k - left];
}