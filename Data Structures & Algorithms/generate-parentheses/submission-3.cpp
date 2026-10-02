class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs("", 0, 0, n, ans);
        return ans;
    }

    void dfs(string curr, int open, int close, int n, vector<string>& ans) {
        if(open > n || close > n) return;

        if(curr.size() == 2*n) {
            ans.push_back(curr);
            return;
        }

        curr += "(";
        dfs(curr, open + 1, close, n, ans);
        curr.pop_back();

        if(open > close) {
            curr += ")";
            dfs(curr, open, close + 1, n, ans);
            curr.pop_back();
        }
    }
};
