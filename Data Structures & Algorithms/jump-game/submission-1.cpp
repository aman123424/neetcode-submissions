class Solution {
public:
    vector<int> dp;

    bool canJump(vector<int>& nums) {
       dp.resize(nums.size(), -1);
       return rec(0, nums); 
    }

    bool rec(int ind, vector<int>& nums) {
        if(ind >= nums.size() - 1) {
            return true;
        }

        if(nums[ind] == 0) return false;

        if(dp[ind] != -1) return dp[ind];

        bool can = false;

        for(int i = 1; i <= nums[ind]; i++) {
            can = can || rec(ind + i, nums);
        }

        return dp[ind] = can;
    }
};
