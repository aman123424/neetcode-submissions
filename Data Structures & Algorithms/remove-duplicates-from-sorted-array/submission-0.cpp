class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0];
        int i = 1, j = 1;

        while(j < nums.size()) {
            if(nums[j] == curr) {
                j++;
            } else {
                swap(nums[i], nums[j]);
                curr = nums[i];
                i++;
                j++;
            }
        }

        return i;
    }
};