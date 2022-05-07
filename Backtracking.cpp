#include <vector>

// Combination Sum //
vector<vector<int>> res;
vector<int> temp;
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  backTrack(candidates, 0, target, 0);
  return res;
}
void backTrack(vector<int> &candidates, int sum, int target, int idx)
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

// Subsets
vector<vector<int>> res;
vector<int> temp;
vector<vector<int>> subsets(vector<int> &nums)
{
  backtrack(nums, 0);
  return res;
}
void backtrack(vector<int> &nums, int idx)
{
  res.push_back(temp);
  for (int i = idx; i < nums.size(); i++)
  {
    temp.push_back(nums[i]);
    backtrack(nums, i + 1);
    temp.pop_back();
  }
}

// Subsets ||
vector<vector<int>> res;
vector<int> temp;
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  backtrack(nums, 0);
  return res;
}
void backtrack(vector<int> &nums, int idx)
{
  res.push_back(temp);
  for (int i = idx; i < nums.size(); i++)
  {
    if (i > idx && nums[i] == nums[i - 1])
      continue;
    temp.push_back(nums[i]);
    backtrack(nums, i + 1);
    temp.pop_back();
  }
}

// Permutations
vector<vector<int>> res;
vector<int> temp;
vector<vector<int>> permute(vector<int> &nums)
{
  backtrack(nums);
  return res;
}
void backtrack(vector<int> &nums)
{
  if (temp.size() == nums.size())
  {
    res.push_back(temp);
    return;
  }
  for (auto num : nums)
  {
    if (find(temp.begin(), temp.end(), num) == temp.end())
    {
      temp.push_back(num);
      backtrack(nums);
      temp.pop_back();
    }
  }
}
