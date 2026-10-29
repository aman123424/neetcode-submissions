class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++) {
            if(mpp[nums[i]] == 1) {
                return true;
            }

            mpp[nums[i]]++;
        }

        return false;
    }
};