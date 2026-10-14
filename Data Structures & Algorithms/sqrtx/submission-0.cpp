class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x;

        int res = 0;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if((long long) mid * mid > x) {
                right = mid - 1;
            } else if((long long) mid * mid < x) {
                left = mid + 1;
                res = mid;
            } else {
                return mid;
            }
        }

        return res;
    }
};