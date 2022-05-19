```cpp
// JUMP GAME
bool canJump(vector<int>& nums) {
  int n = nums.size();
  vector<bool> memo(n, false);
  memo[0] = true;
  int i, k = 1;
  for (i=0; i<n && memo[i]; i++) {
      int j;
      for (j=k; j<=i+nums[i]; j++) {
          if (j == n) return true;
          memo[j] = true;
      }
      k = j;
  }
  return i == n;
}
```



```cpp
// JUMP GAME 2
int jump(vector<int>& nums) {
  int n = nums.size();
  vector<int> memo(n, INT_MAX);
  memo[0] = 0;
  int i, k = 1;
  for (int i=0; i<n; i++) {
      int j;
      for (j=k; j<=i+nums[i]; j++) {
          if (j == n) return memo[n-1];
          memo[j] = memo[i] + 1;
      }
      k = j;
  }
  return memo[n-1];
}
```



```cpp
// MAX SUM SUB-ARRAY
int maxSubArray(vector<int>& nums) {
  int cur = 0, res = 0, largest = INT_MIN;
  for (int i=0; i<nums.size(); i++) {
      cur += nums[i];
      if (cur < 0) cur = 0;
      res = max(res, cur);
      largest = max(nums[i], largest);
  }
  return res == 0 ? largest : res;
}
```



```cpp
// 134. GAS STATION
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int n = gas.size();
  vector<int> combined(n);
  for (int i=0; i<n; i++) combined[i] = gas[i] - cost[i];
  for (int i=0; i<n; i++) {
      int cur = 0, j;
      for (j=i; j<n || j%n != i; j++) {
          cur += combined[j%n];
          if (cur < 0) break;
      }
      if (j > i && i == j%n) return i;
      if (i > j) return -1;
      i = j;
  }
  return -1;
}
```
