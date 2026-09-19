class Solution {
public:
    vector<vector<int>> dp;

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(), vector<int>(amount + 1, -1));
        int ans = dfs(0, amount, coins);
        return ans == INT_MAX ? -1 : ans;
    }

    int dfs(int i, int amount, vector<int>& coins) {
        if(amount <= 0) {
            return 0;
        }

        if(i == coins.size()) return INT_MAX;

        if(dp[i][amount] != -1) return dp[i][amount];

        int currCoin = coins[i];
        int take = INT_MAX; 
        if(amount >= currCoin) {
            int result = dfs(i, amount - currCoin, coins);

            if(result != INT_MAX) {
                take = 1 + result;
            }
        }

        int skip = dfs(i + 1, amount, coins);
    
        return dp[i][amount] = min(skip, take);
    }
};
