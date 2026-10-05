class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> seen(nums.size(), 0);

        for(int num : nums) {
            if(num > 0 && num <= nums.size()) {
                seen[num - 1] = 1;
            }
        }

        for(int i = 0; i < seen.size(); i++) {
            if(seen[i] == 0) return i + 1;
        }

        return seen.size() + 1;
    }
};