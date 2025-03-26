int partition(int *a, int left, int right) {
  int pivot = a[left];
  while (left != right) {
    while (left < right && a[right] >= pivot)
      right--;
    a[left] = a[right];
    while (left < right && a[left] < pivot)
      left++;
    a[right] = a[left];
  }
  a[left] = pivot;
  return left;
}

void quickSort(int *a, int left, int right) {
  if (left >= right)
    return;
  int pivot_pos = partition(a, left, right);
  quickSort(a, left, pivot_pos - 1);
  quickSort(a, pivot_pos + 1, right);
}