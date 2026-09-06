class Solution {
public:
    vector<int> dp;

    int numDecodings(string s) {
        dp.resize(s.size(), -1);
        return recursive(0, s);
    }

    int recursive(int i, string& s) {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int res = recursive(i + 1, s);
        
        if(i < s.size() - 1) {
            if(s[i] == '1' || s[i] == '2' && s[i + 1] < '7') {
                res += recursive(i + 2, s);
            } 
        }

        return dp[i] = res;
    }
};
