class Solution {
public:
    vector<vector<int>> dp;

    int numDistinct(string s, string t) {
        dp.resize(s.size(), vector<int>(t.size(), -1));
        return backtrack(0, 0, s, t);
    }

    int backtrack(int sIndex, int tIndex, string& s, string& t) {
        if(tIndex == t.size()) return 1;

        if(sIndex == s.size()) return 0;

        if(dp[sIndex][tIndex] != -1) return dp[sIndex][tIndex];

        if(s[sIndex] == t[tIndex]) {
            return dp[sIndex][tIndex] = backtrack(sIndex + 1, tIndex + 1, s, t) + backtrack(sIndex + 1, tIndex, s, t);
        }

        return dp[sIndex][tIndex] = backtrack(sIndex + 1, tIndex, s, t);
    }
};
