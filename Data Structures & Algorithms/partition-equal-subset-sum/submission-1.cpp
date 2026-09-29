class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (sum(nums) % 2 != 0) {
            return false;
        }

        int target = sum(nums) / 2;
        vector<bool> dp(target + 1, false);
        vector<bool> nextDp(target + 1, false);

        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i]) {
                    nextDp[j] = dp[j] || dp[j - nums[i]];
                } else {
                    nextDp[j] = dp[j];
                }
            }
            swap(dp, nextDp);
        }

        return dp[target];
    }

    int sum(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        return total;
    }
};
