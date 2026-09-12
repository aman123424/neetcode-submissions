class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i - 1; j >= -1; --j) {
                int LIS = dp[i + 1][j + 1]; // Not including nums[i]

                if (j == -1 || nums[j] < nums[i]) {
                    LIS = max(LIS, 1 + dp[i + 1][i + 1]); // Including nums[i]
                }

                dp[i][j + 1] = LIS;
            }
        }

        return dp[0][0];
    }
};
