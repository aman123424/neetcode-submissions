class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        
        int carry = 1;

        for(int i = 0; i < digits.size(); i++) {
            int sum = digits[i] + carry;
            digits[i] = sum%10;
            if(sum <= 9) {
                carry = 0;
                break;
            }
        }

        if(carry) digits.push_back(1);
        reverse(digits.begin(), digits.end());

        return digits;
    }
};
