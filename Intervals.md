```cpp
// Merge Intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end());

  int start = intervals[0][0];
  int end = intervals[0][1];
  int n = intervals.size();

  vector<vector<int>> res;

  for (int i=1; i<n; i++) {
    if (intervals[i][0] <= end) {
      end = max(end, intervals[i][1]);
    }
    else {
      res.push_back({start, end});
      start = intervals[i][0];
      end = intervals[i][1];
    }
  }

  res.push_back({start, end});

  return res;
}
```

```cpp
// Insert Interval
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  int n = intervals.size();
  vector<vector<int>> res;

  for (int i=0; i<n; i++) {
    if (newInterval[0] < intervals[i][0] && newInterval[1] < intervals[i][0]) {
      // don't merge
      res.push_back(newInterval);
      fill(intervals, i, res);
      return res;
    }
    else if (newInterval[0] <= intervals[i][1]) {
      // merge
      int start = min(newInterval[0], intervals[i][0]);
      int end = max(newInterval[1], intervals[i][1]);

      int j;
      for (j=i+1; j<n; j++) {
          if (intervals[j][0] > end) break;
          else {
              end = max(end, intervals[j][1]);
          }
      }

      res.push_back({start, end});

      // fill
      fill(intervals, j, res);

      return res;
    }
    else {
      res.push_back(intervals[i]);
    }
  }

  res.push_back(newInterval);

  return res;
}

void fill(vector<vector<int>>& intervals, int idx, vector<vector<int>>& res) {
  for (int i=idx; i<intervals.size(); i++) {
    res.push_back(intervals[i]);
  }
}
```
