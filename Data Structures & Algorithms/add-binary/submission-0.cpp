class Solution {
public:
    int countOnes(vector<char>& s) {
        int count = 0;
        for(char ch : s) {
            if(ch == '1') count++;
        }
        return count;
    }

    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() - 1, j = b.size() - 1;
        char carry = '0';

        while(i >= 0 || j >= 0 || carry == '1') {
            char digit1 = i >= 0 ? a[i] : '0';
            char digit2 = j >= 0 ? b[j] : '0';

            vector<char> temp = {digit1, digit2, carry};
            char sum = countOnes(temp) == 0 || countOnes(temp) == 2 ? '0' : '1';
            carry =  countOnes(temp) > 1 ? '1' : '0';

            ans.insert(ans.begin(), sum);
            
            i--; j--;
        }

        return ans;
    }
};