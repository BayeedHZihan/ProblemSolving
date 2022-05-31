```cpp
// Search in rotated sorted array

int search(vector<int>& nums, int target) {
  int n = nums.size(), l = 0, r = n-1, start = 0;
  while (l <= r) {
      int mid = l + (r-l)/2;
      if (nums[mid] < nums[start]) start = mid;
      if (nums[mid] < nums[r]) r = mid - 1;
      else l = mid + 1;
  }
  l = target >= nums[start] && target <= nums[n-1] ? start : 0;
  r = target >= nums[start] && target <= nums[n-1] ? n-1 : start - 1;
  while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) return mid;
      if (target > nums[mid]) l = mid + 1;
      else r = mid - 1;
  }
  return -1;
}
```

```cpp
// Find Minimum in Rotated Sorted Array

int findMin(vector<int>& nums) {
  int n = nums.size(), l = 0, r = n-1, start = 0;
  while (l <= r) {
      int mid = l + (r-l)/2;
      if (nums[mid] < nums[start]) start = mid;
      if (nums[r] < nums[mid]) l = mid + 1;
      else r = mid - 1;
  }
  return nums[start];
}
```
