class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        
        string first = strs[0], last = strs.back();
        
        int ind = 0;
        string ans = "";

        while(ind < first.size() && first[ind] == last[ind]) {
            ans += first[ind++];
        }

        return ans;
    }
};