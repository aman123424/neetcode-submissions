class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = n - 1; i >= 0; --i) {
            vector<bool> newDp(n + 1, false);
            for (int open = 0; open < n; ++open) {
                if (s[i] == '*') {
                    newDp[open] = dp[open + 1] ||
                                  (open > 0 && dp[open - 1]) || dp[open];
                } else if (s[i] == '(') {
                    newDp[open] = dp[open + 1];
                } else if (open > 0) {
                    newDp[open] = dp[open - 1];
                }
            }
            dp = newDp;
        }
        return dp[0];
    }
};
