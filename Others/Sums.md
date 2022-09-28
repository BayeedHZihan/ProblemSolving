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

```cpp
// 3Sum Smaller
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;

        for (int i=0; i<n; i++) {
            cnt += cntForCur(nums[i], i+1, n-1, nums, target);
        }

        return cnt;
    }

    int cntForCur(int pivot, int startIdx, int endIdx, vector<int>& nums, int target) {
        int cnt = 0;

        while (startIdx < endIdx) {
            if (pivot + nums[startIdx] + nums[endIdx] >= target) {
                endIdx--;
            }
            else {
                cnt += endIdx - startIdx;
                startIdx++;
            }
        }

        return cnt;
    }
};

/*
-2,0,0,1,3 -> -2,0,3; -2,0,3; -2,0,1, -2,0,1; 0,0,1, -2,0,0
*/
```

```cpp
// 3Sum Closest
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = INT_MAX, minDif = INT_MAX;

        for (int i=0; i<n-2; i++) {
            int cur = findClosest(nums[i], i+1, n-1, nums, target);
            if (abs(target - cur) < minDif) {
                minDif = abs(target - cur);
                res = cur;
            }
        }

        return res;
    }

    int findClosest(int pivot, int startIdx, int endIdx, vector<int>& nums, int target) {
        int closestDif = INT_MAX, closest = INT_MAX;

        while (startIdx < endIdx) {
            int cursum = pivot + nums[startIdx] + nums[endIdx];
            if (abs(cursum - target) < closestDif) {
                closestDif = abs(cursum - target);
                closest = cursum;
            }

            if (cursum > target) endIdx--;
            else startIdx++;
        }

        return closest;
    }
};

/*
[-4,-1,1,2]
*/
```

```cpp
// 4 Sum
class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i=0; i<n; i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                bool sameAsLast = false;
                for (int j=i+1; j<n; j++) {
                    if (!sameAsLast) {
                        findSums(nums[i], nums[j], j+1, n-1, nums, target);
                    }
                    sameAsLast = j < n-1 && nums[j] == nums[j+1];
                }
            }
        }

        return res;
    }

    void findSums(int first, int second, int startIdx, int endIdx, vector<int>& nums, int target) {
        while (startIdx < endIdx) {

            long long cursum = (long long)first + (long long)second + (long long)nums[startIdx] + (long long)nums[endIdx];

            if (cursum == target) {
                res.push_back({first, second, nums[startIdx], nums[endIdx]});

                startIdx++;
                while(startIdx < nums.size() && nums[startIdx] == nums[startIdx-1]) {startIdx++;}

                endIdx--;
                while(endIdx >= 0 && nums[endIdx] == nums[endIdx+1]) {endIdx--;}
            }
            else if (cursum > target) endIdx--;
            else startIdx++;
        }
    }
};

/*
1,2,2,2,2,2
-2,-1,0,0,1,2
*/
```

```cpp
// 4 Sum II
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;
        for (auto n3: nums3) {
            for (auto n4: nums4) {
                umap[n3+n4]++;
            }
        }

        int cnt = 0;
        for (auto n1: nums1) {
            for (auto n2: nums2) {
                int target = - n1 - n2;
                cnt += umap[target];
            }
        }

        return cnt;
    }
};
```
