class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int ans = 0;

        for(int i = 0; i < 32; i++) {
            int bit1 = (a >> i) & 1;
            int bit2 = (b >> i) & 1;
            
            int ans_curr_bit = bit1 ^ bit2 ^ carry;
            carry = (bit1 + bit2 + carry) >= 2 ? 1 : 0;
            
            if(ans_curr_bit) {
                ans |= (1 << i);
            }
        }

        return ans;
    }
};
