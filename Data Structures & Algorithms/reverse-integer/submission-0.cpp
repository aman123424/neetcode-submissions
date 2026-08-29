class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        const int MIN = INT_MIN, MAX = INT_MAX;

        while(x != 0) {
            int digit = x%10;
            x /= 10;

            if(ans > MAX / 10 || (ans == MAX / 10 && digit > MAX%10)) return 0;
            if(ans < MIN / 10 || (ans == MIN / 10 && digit < MIN%10)) return 0;

            ans = (ans * 10) + digit;
        }

        return ans;
    }
};
