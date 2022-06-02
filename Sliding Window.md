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

```cpp
// Best Time to Buy and Sell Stock

int maxProfit(vector<int>& prices) {
  int buy = 0, sell = 0, res = 0;
  while (sell < prices.size()) {
      res = max(res, prices[sell] - prices[buy]);
      if (prices[sell] < prices[buy]) buy = sell;
      else sell++;
  }
  return res;
}
```

```cpp
// Longest Repeating Character Replacement

int characterReplacement(string s, int k) {
  int l = 0, res = 0, n = s.length(), curmax = 0;
  unordered_map<char, int> umap;
  for (int r = 0; r < n; r++) {
      umap[s[r]]++;
      curmax = max(curmax, umap[s[r]]);
      while ((r-l+1) - curmax > k) {
          umap[s[l]]--;
          l++;
          curmax = 0;
          for (auto i=umap.begin(); i!=umap.end(); i++) {
              curmax = max(curmax, i->second);
          }
      }
      res = max(res, r-l+1);
  }
  return res;
}
```
