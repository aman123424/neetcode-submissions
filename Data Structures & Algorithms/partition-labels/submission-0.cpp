class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mpp;

        for(int i = 0; i < s.size(); i++) {
            mpp[s[i]] = i;
        }

        vector<int> ans;
        int size = 0, end = 0;

        for(int i = 0; i < s.size(); i++) {
            size++;
            end = max(end, mpp[s[i]]);

            if(i == end) {
                ans.push_back(size);
                size = 0;
            }
        }

        return ans;
    }
};
