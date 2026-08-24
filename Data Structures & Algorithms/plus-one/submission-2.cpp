class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;

        while(index >= 0 && digits[index] == 9) {
            if(index == 0) {
                digits.insert(digits.begin(), 0);
                index++;
            }
            
            digits[index] = 0;
            index--;
        }

        digits[index]++;
        return digits;
    }
};
