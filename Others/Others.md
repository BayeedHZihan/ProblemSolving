```cpp
// Shifting Letters II
// Line sweeping / Scanline algorithm
string shiftingLetters(string s, vector<vector<int>>& shifts) {
  int n = s.size();
  vector<int> pref(n+1);

  // mark start and end indexes
  for (auto shift: shifts) {
    int from = shift[0];
    int to = shift[1];
    int dir = shift[2];

    if (dir == 1) {
      pref[from]++;
      pref[to+1]--;
    }
    else {
      pref[from]--;
      pref[to+1]++;
    }
  }

  for (int i=1; i<n; i++) {
    pref[i] += pref[i-1];
  }

  for (int i=0; i<n; i++) {
    int ans = s[i] + pref[i];
    if (ans >= 'a' && ans <= 'z') s[i] += pref[i];
    else if (ans > 'z') {
      while (ans > 'z') ans -= 26;
      s[i] = ans;
    }
    else {
      while (ans < 'a') ans += 26;
      s[i] = ans;
    }
  }

  return s;
}
```
