```cpp
// Largest Number
string largestNumber(vector<int>& nums) {
  if (allZero(nums)) return "0";
  vector<string> numstr;
  for (auto num: nums) {
    numstr.push_back(to_string(num));
  }

  sort(numstr.begin(), numstr.end(), [=](string a, string b){
    return a + b > b + a;
  });

  string res;
  for (auto s: numstr) {
      res += s;
  }

  return res;
}

bool allZero(vector<int> nums) {
  for (auto num: nums) {
      if (num != 0) return false;
  }
  return true;
}
```
