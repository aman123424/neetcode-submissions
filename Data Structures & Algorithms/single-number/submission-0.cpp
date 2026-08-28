class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int num : nums) {
            mpp[num]++;
        }

        for(auto it : mpp) {
            if(it.second == 1) return it.first; 
        }
    }
};
