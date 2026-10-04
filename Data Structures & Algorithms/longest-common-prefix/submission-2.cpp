class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for(int i = 1; i < strs.size(); i++) {
            int ind = 0;
            string curr = "";
            while(ind < ans.size() && ind < strs[i].size() && ans[ind] == strs[i][ind]) {
                curr += ans[ind++];
            }

            ans = curr;
        }

        return ans;
    }
};