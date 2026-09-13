class Solution {
public:
    int ans = 0;
    vector<vector<int>> dp;

    int countSubstrings(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        dfs(0, 0, s);
        return ans;
    }

    void dfs(int start, int end, string& s) {
        if(start >= s.size()) {
            return;
        }

        if(end >= s.size()) {
            dfs(start + 1, start + 1, s);
            return;
        }

        if(isPalindrome(s, start, end)) {
            ans++;
        }

        dfs(start, end + 1, s);
    }

    bool isPalindrome(string& s, int start, int end) {
        if(start >= end) {
            return true;
        }
        
        if(dp[start][end] != -1) return dp[start][end];

        if(s[start] != s[end]) {
            return dp[start][end] = false;
        }

        return dp[start][end] =
            isPalindrome(s, start + 1, end - 1);
    }
};
