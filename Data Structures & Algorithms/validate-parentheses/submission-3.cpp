class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> mpp;
        mpp['('] = ')';
        mpp['['] = ']';
        mpp['{'] = '}';

        for(int i = 0; i < s.size(); i++) {
            // if open bracket
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if(st.empty()) return false;

                char ch = st.top();
                st.pop();
                if(mpp[ch] != s[i]) return false;
            }
        }

        if(!st.empty()) return false;

        return true;
    }
};
