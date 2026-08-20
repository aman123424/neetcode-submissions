class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = 1;

        while(r < n) {
            if(height[r] < height[l]) break;
            r++;
            l++;
        }

        int totalWater = 0;

        //Count from left
        while(r < n) {
            int blacks = 0;
            while(r < n && height[r] < height[l]){
                blacks += height[r++];
            }

            if(r == n) break;
            
            totalWater += height[l] * (r - l - 1) - blacks;
            l = r;
            r++;
        }

        int limit = l;
        r = n - 1;
        l = n - 2;

        while(l >= 0) {
            if(height[l] < height[r]) break;
            l--;r--;
        }

        while(l >= limit) {
            int blacks = 0;

            while(l >= limit && height[r] > height[l]){
                blacks += height[l--];
            }

            if(l < limit) break;

            totalWater += height[r] * (r - l - 1) - blacks;
            r = l;
            l--;
        } 

        return totalWater;
    }
};
