```cpp
// Remove All Adjacent Duplicates in String II
string removeDuplicates(string s, int k) {
  stack<pair<char,int>> Stack;

  for (auto c: s) {
    int curval = Stack.empty() || Stack.top().first != c ? 1 : Stack.top().second + 1;

    Stack.push({c, curval});

    if (curval == k) {
        removeKValsFromStack(Stack, k);
    }
  }

  return buildRes(Stack);
}

string buildRes(stack<pair<char,int>>& Stack) {
  string res;

  while (!Stack.empty()) {
    res.push_back(Stack.top().first);
    Stack.pop();
  }

  reverse(res.begin(), res.end());
  return res;
}

void removeKValsFromStack(stack<pair<char,int>>& Stack, int k) {
  while (k--) Stack.pop();
}
```
