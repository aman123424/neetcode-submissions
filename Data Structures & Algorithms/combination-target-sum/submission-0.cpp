class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> subset;

        dfs(0, 0, target, nums, subset, result);

        return result;
    }

    void dfs(int i, int sum, int target, const vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
        if(i >= nums.size()) {
            if(sum == target) result.push_back(subset);
            return;
        }

        if(sum > target) {
            return;
        }

        sum += nums[i];
        subset.push_back(nums[i]);
        dfs(i, sum, target, nums, subset, result);

        subset.pop_back();
        sum -= nums[i];
        dfs(i + 1, sum, target, nums, subset, result);
    }
};
