```cpp
// 3 Sum
class Solution {
public:
  vector<vector<int>> res;

  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i=0; i<n; i++) {
      if (i == 0 || nums[i] != nums[i-1]) findComplement(nums[i], i+1, n-1, nums);
    }

    return res;
  }

  void findComplement(int pivot, int startIdx, int endIdx, vector<int>& nums) {
    while (startIdx < endIdx) {
      int left = nums[startIdx];
      int right = nums[endIdx];

      if (left + right < -pivot) startIdx++;
      else if (left + right > -pivot) endIdx--;
      else {
        res.push_back({pivot, left, right});

        startIdx++;
        while(startIdx < nums.size() && nums[startIdx] == nums[startIdx-1]) startIdx++;

        endIdx--;
        while(endIdx >= 0 && nums[endIdx] == nums[endIdx+1]) endIdx--;
      }
    }
  }
};

/*
[-4,-1,-1,0,1,2]
*/
```
