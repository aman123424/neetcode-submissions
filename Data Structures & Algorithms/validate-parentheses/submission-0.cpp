class Solution {
public:
    bool isClosing(char ch) {
        if(ch == ')' || ch == ']' || ch == '}') {
            return true;
        }

        return false;
    }

    bool isMatching(char ch1, char ch2) {
        if(ch1 == ')' && ch2 == '(') return true;
        if(ch1 == ']' && ch2 == '[') return true;
        if(ch1 == '}' && ch2 == '{') return true;

        return false;
    }

    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++) {
            if(isClosing(s[i])) {
                if(st.empty()) return false;

                if(!isMatching(s[i], st.top())){
                    return false;
                }
                st.pop();
            }else {
                st.push(s[i]);
            }
        }

        if(st.empty()) return true;
        return false;
    }
};
