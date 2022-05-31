```cpp
// Longest Substring Without Repeating Characters

int lengthOfLongestSubstring(string s) {
  int l = 0, r = 0, n = s.size();
  int res = 0;
  unordered_set<char> uset;
  while (r < n) {
      if (uset.find(s[r]) != uset.end()) {
          uset.erase(s[l]);
          l++;
      }
      else {
          res = max(res, r-l+1);
          uset.insert(s[r]);
          r++;
      }
  }
  return res;
}
```
