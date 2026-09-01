class Solution {
public:
    vector<int> memo;

    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        memo[i] = max(dfs(nums, i + 1),
                    nums[i] + dfs(nums, i + 2));
        return memo[i];
    }
};
