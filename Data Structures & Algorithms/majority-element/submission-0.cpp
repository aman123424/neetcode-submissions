class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int counter = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == ans) {
                counter++;
            } else {
                counter--;
            }  

            if(counter < 0) ans = nums[i];
        }

        return ans;
    }
};