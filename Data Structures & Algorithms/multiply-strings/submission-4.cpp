class Solution {
public:
    string add(string num1, string num2) {
        int size1 = num1.size(), size2 = num2.size();
        string res = "";
        int carry = 0;
        int i = size1 - 1, j = size2 - 1;

        while(i >= 0 && j >= 0) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';

            int sum = digit1 + digit2 + carry;
            char ch = sum%10 + '0';
            res.insert(res.begin(), ch);
            carry = sum/10;
            i--; j--;
        }
        
        while(j >= 0) {
            int sum = (num2[j] - '0') + carry;
            res.insert(res.begin(), sum%10 + '0');
            carry = sum/10;
            j--;
        }

        if(carry) res.insert(res.begin(), carry + '0');
        
        return res;
    }

    string multiplySingleDigit(string num, int number) {
        string res = "";
        int carry = 0;

        for(int i = num.size() - 1; i >= 0; i--) {
            int digit = num[i] - '0';

            int ans = (digit * number) + carry;

            
            res.insert(res.begin(), ans%10 + '0');
            carry = ans/10; 
        }

        if(carry) {
            res.insert(res.begin(), carry + '0');
        }

        return res;
    }

    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        string result = "";

        for(int i = num1.size() - 1; i >= 0; i--) {
            int digit = num1[i] - '0';

            string multiplication = multiplySingleDigit(num2, digit);
            
            for(int units = 0; units < num1.size() - 1 - i; units++) {
                multiplication += "0";
            }

            result = add(result, multiplication);
        }

        return result;
    }
};
