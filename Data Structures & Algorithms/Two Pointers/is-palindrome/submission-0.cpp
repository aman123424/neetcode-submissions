class Solution {
public:
    
    bool isValidChar(char &ch) {
        if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if(ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
            return true;
        }

        return false;
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.size();

        while(left <= right) {
            if(!isValidChar(s[left])) {
                left++;
                continue;
            }

            if(!isValidChar(s[right])) {
                right--;
                continue;
            }

            if(s[left] != s[right]) return false;

            left++; right --;
        }

        return true;
    }
};
