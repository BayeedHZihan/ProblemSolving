```cpp
// Combination Sum
vector<vector<int>> res;
vector<int> temp;
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  backTrack(candidates, 0, target, 0);
  return res;
}
void backTrack(vector<int>& candidates, int sum, int target, int idx)
{
  if (sum > target)
    return;
  if (sum == target)
  {
    res.push_back(temp);
    return;
  }
  for (int i = idx; i < candidates.size(); i++)
  {
    temp.push_back(candidates[i]);
    backTrack(candidates, sum + candidates[i], target, i);
    temp.pop_back();
  }
}
```

```cpp
// **Combination Sum ||**
// set<vector<int>> Set;
vector<vector<int>> res;
vector<int> temp;

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
  sort(candidates.begin(), candidates.end());
  backtrack(candidates, target, 0, 0);
  // vector<vector<int>> res;
  // for (auto i=Set.begin(); i!=Set.end(); i++) {
  //     res.push_back(*i);
  // }
  return res;
}

void backtrack(vector<int> &candidates, int target, int sum, int idx)
{
  if (sum > target) return;
  if (sum == target) {
    // Set.insert(temp);
    res.push_back(temp);
    return;
  }
  for (int i = idx; i < candidates.size(); i++) {
    if (i > idx && candidates[i] == candidates[i - 1])
      continue;
    temp.push_back(candidates[i]);
    backtrack(candidates, target, sum + candidates[i], i + 1);
    temp.pop_back();
  }
}
```

```cpp
// Subsets
vector<vector<int>> res;
vector<int> temp;
vector<vector<int>> subsets(vector<int> &nums) {
  backtrack(nums, 0);
  return res;
}

void backtrack(vector<int> &nums, int idx) {
  res.push_back(temp);
  for (int i = idx; i < nums.size(); i++)
  {
    temp.push_back(nums[i]);
    backtrack(nums, i + 1);
    temp.pop_back();
  }
}
```

```cpp
// Subsets ||
vector<vector<int>> res;
vector<int> temp;

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  backtrack(nums, 0);
  return res;
}

void backtrack(vector<int> &nums, int idx) {
  res.push_back(temp);
  for (int i = idx; i < nums.size(); i++) {
    if (i > idx && nums[i] == nums[i - 1]) continue;
    temp.push_back(nums[i]);
    backtrack(nums, i + 1);
    temp.pop_back();
  }
}
```

```cpp
// Permutations
vector<vector<int>> res;
vector<int> temp;

vector<vector<int>> permute(vector<int> &nums){
  backtrack(nums);
  return res;
}

void backtrack(vector<int> &nums) {
  if (temp.size() == nums.size()) {
    res.push_back(temp);
    return;
  }
  for (auto num : nums) {
    if (find(temp.begin(), temp.end(), num) == temp.end()){
      temp.push_back(num);
      backtrack(nums);
      temp.pop_back();
    }
  }
}
```

```cpp
// word search

string str = "";
// unordered*set<string> visited;
bool exist(vector<vector<char>> &board, string word) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (backtrack(board, word, i, j)) return true;
    }
  }
  return false;
}

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool backtrack(vector<vector<char>> &board, string word, int row, int col) {
  if (str.size() > word.size()) return false;
  if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '*') return false;
  if (str.size() < word.size() && word[str.size()] != board[row][col]) return false;
  str += board[row][col];
  if (str == word) return true;
  char cur = board[row][col];
  board[row][col] = '*';
  // visited.insert(to_string(row) + to_string(col));
  for (auto d : dir) {
    if (backtrack(board, word, row + d.first, col + d.second)) return true;
  }
  str.pop_back();
  board[row][col] = cur;
  // visited.erase(to_string(row) + to_string(col));
  return false;
}
```

```cpp
// Palindrome Partitioning

vector<vector<string>> res;
set<vector<string>> Set;
vector<string> temp;
vector<vector<string>> partition(string s) {
    backtrack(s, 0, "");
    for (auto i=Set.begin(); i!=Set.end(); i++)
        res.push_back(*i);
    return res;
}
void backtrack(string s, int idx, string cur) {
    for (int i=idx; i<s.size(); i++) {
        cur += s[i];
        if (pal(cur)) {
            temp.push_back(cur);
            backtrack(s, i+1, "");
            if (i+1 == s.size()) Set.insert(temp);
                // res.push_back(temp);
            temp.pop_back();
        }
        else {
            backtrack(s, i+1, cur);
        }
    }
}
bool pal(string str) {
    if (str.size() == 0) return false;
    int l = 0, r = str.size() - 1;
    while(l < r) {
        if (str[l] != str[r]) return false;
        l++, r--;
    }
    return true;
}

/*
aaba
bt(0, "")
    cur = s[0] = a
    temp(a)
    bt(1, "")
        cur = s[1] = a
        temp(a, a)
        bt(2, "")
            cur = s[2] = b
            temp(a, a, b)
            bt(3, "")
                cur = s[3] = a
                temp(a, a, b, a)
                bt(4, "")
                temp(a, a, b)
            temp(a, a)
        temp(a)
    temp()


a, a, b, a
a, aba
*/
```

```cpp
vector<string> res;
vector<string> generateParenthesis(int n) {
  dfs(n, "", 0, 0);
  return res;
}
void dfs(int n, string cur, int left, int right) {
  if (right > left || left > n) return;
  if (left == n && right == n) {
    res.push_back(cur);
    return;
  }
  dfs(n, cur+'(', left+1, right);
  dfs(n, cur+')', left, right+1);
}
```
