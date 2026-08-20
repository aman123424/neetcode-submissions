class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int totalWater = 0;
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;

        while(left <= right) {
            if(height[left] <= height[right]) {
                if(leftMax <= height[left]) {
                    leftMax = height[left];
                } else {
                    totalWater += leftMax - height[left];
                }
                left++;
            } else {
                if(rightMax <= height[right]) {
                    rightMax = height[right];
                } else {
                    totalWater += rightMax - height[right];
                }
                right--;
            }
        }

        return totalWater;
    }
};
