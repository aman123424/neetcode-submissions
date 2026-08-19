class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0, j = n - 1;
        int maxi = 0;

        while(i < j) {
            int left = heights[i];
            int right = heights[j];
            maxi = max(maxi, (j - i) * min(left, right));
            
            if(left < right) {
                i++;
            } else{
                j--;
            }
        }

        return maxi;
    }
};
