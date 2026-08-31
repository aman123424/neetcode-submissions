class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(int l, int r, string& s) {
        
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }

        return true;
    } 

    void dfs(int i, string& s, vector<string>& part) {
        if(i >= s.size()) {
            ans.push_back(part);
            return;
        }

        for(int j = i; j < s.size(); j++) {
            if(isPalindrome(i, j, s)) {
                part.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s, part);
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(0, s, part);
        return ans;
    }
};
