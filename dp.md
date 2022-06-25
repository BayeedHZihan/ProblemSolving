```cpp
// Coin Change
int coinChange(vector<int>& coins, int amount) {
  vector<int> dp(amount+1, INT_MAX);
  dp[0] = 0;
  for (int i=0; i<=amount; i++) {
      if (dp[i] < INT_MAX) {
          for (auto coin: coins) {
              if (coin <= amount - i) dp[i+coin] = min(dp[i+coin], dp[i]+1);
          }
      }
  }
  return dp[amount] == INT_MAX ? -1 : dp[amount];
}
```

```cpp
// Climbing Stairs
int climbStairs(int n) {
  if (n < 4) return n;
  int first = 1, second = 2;
  for (int i=3; i<=n; i++) {
      int third = first + second;
      first = second;
      second = third;
  }
  return second;
}
```

```cpp
// House Robber
int rob(vector<int>& nums) {
  int n = nums.size();
  if (n == 1) return nums[0];
  if (n == 2) return max(nums[0], nums[1]);
  nums[2] += nums[0];
  for (int i=3; i<n; i++) {
      nums[i] += max(nums[i-2], nums[i-3]);
  }
  return max(nums[n-1], nums[n-2]);
}
```

```cpp
// Circular House Robber
int rob(vector<int>& nums) {
  int n = nums.size();
  vector<int> vec = nums;
  if (n == 1) return nums[0];
  if (n == 2) return max(nums[0], nums[1]);
  if (n == 3) return max(max(nums[0], nums[1]), nums[2]);
  vec[2] += vec[0];
  for (int i=3; i<n-1; i++) {
      vec[i] += max(vec[i-2], vec[i-3]);
  }
  nums[n-3] += nums[n-1];
  for (int i=n-4; i>0; i--) {
      nums[i] += max(nums[i+2], nums[i+3]);
  }
  return max(max(vec[n-2], vec[n-3]), max(nums[1], nums[2]));
}
```

```cpp
// Longest Palindromic Subsequence
string str;
int n;
string longestPalindrome(string s) {
  n = s.size();
  string res = "";
  str = s;
  for (int i=0; i<n; i++) {
      string cur = findLongest(i-1, i+1);
      if (i>0 && s[i] == s[i-1]) {
          string doublePivot = findLongest(i-2, i+1);
          if (doublePivot.size() > cur.size()) cur = doublePivot;
      }
      if (cur.size() > res.size()) res = cur;
  }
  return res;
}
string findLongest(int l, int r) {
  while(l>=0 && r<n && str[l] == str[r]) l--, r++;
  return str.substr(l+1, r-l-1);
}
```

```cpp
// Count Palindromic Substrings
string str;
int n;
int countSubstrings(string s) {
  int res = 0;
  n = s.size();
  str = s;
  for (int i=0; i<n; i++) {
      res += countCurPivot(i-1, i+1);
      if (i>0 && s[i-1]==s[i]) res += countCurPivot(i-2, i+1);
  }
  return res;
}
int countCurPivot(int l, int r) {
  int cnt = 1;
  while (l>=0 && r<n && str[l]==str[r]) cnt++, l--, r++;
  return cnt;
}
```

```cpp
// Max Product Subarray
int maxProduct(vector<int>& nums) {
  int res = nums[0], n = nums.size(), l = 0, r = 0;
  for (int i=0; i<n; i++) {
      l = (l ? l : 1) * nums[i];
      r = (r ? r : 1) * nums[n-1-i];
      res = max(res, max(l, r));
  }
  return res;
}
```
