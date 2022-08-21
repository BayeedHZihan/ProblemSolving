```cpp
// Longest Palindromic Substring
int n;
string str;
string longestPalindrome(string s) {
  n = s.size();
  str = s;
  string res;
  int reslen = 0;

  for (int i=0; i<n; i++) {
    string curmax = pal(i-1, i+1);
    string doublePivot = pal(i, i+1);
    int l1 = curmax.size(), l2 = doublePivot.size();

    if (l1 > l2) {
      if (l1 > reslen) {
          reslen = l1;
          res = curmax;
      }
    }
    else {
      if (l2 > reslen) {
          reslen = l2;
          res = doublePivot;
      }
    }
  }

  return res;
}

string pal(int l, int r) {
  while (l >= 0 && r < n && str[l] == str[r]) {
    l--, r++;
  }

  return str.substr(l+1, r-l-1);
}
```
