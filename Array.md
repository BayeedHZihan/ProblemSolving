```cpp
// Top K Frequent Elements

vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> umap;
  for (int num: nums) umap[num]++;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  for (auto i=umap.begin(); i!=umap.end(); i++) {
      pq.push({i->second, i->first});
      if (pq.size() > k) pq.pop();
  }
  vector<int> res;
  while (!pq.empty()) {
      res.push_back(pq.top().second);
      pq.pop();
  }
  return res;
}
```

```cpp
// Longest Consecutive Sequence

int longestConsecutive(vector<int>& nums) {
  int res = 0;
  unordered_set<int> uset;
  for (auto n: nums) uset.insert(n);
  for (auto n: nums) {
      if (uset.find(n-1) == uset.end()) {
          int temp = n;
          int cnt = 0;
          while (uset.find(temp) != uset.end()) {
              cnt++;
              temp++;
          }
          res = max(cnt, res);
      }
  }
  return res;
}
```
