class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) nums[i] = 0;
        }

        for(int num : nums) {
            int val = abs(num);
            if(val >= 1 && val <= nums.size()) {
                if(nums[val - 1] > 0) {
                    nums[val - 1] *= -1;
                } else {
                    nums[val - 1] = -1 * (nums.size() + 1);
                }
            }
        }

        for(int i = 1; i <= nums.size(); i++) {
            if(nums[i - 1] >= 0) return i;
        }

        return nums.size() + 1;
    }


};