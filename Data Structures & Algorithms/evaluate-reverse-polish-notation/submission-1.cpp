class Solution {
public:
    bool isOperator(string s) {
        if(s == "+" || s == "-" || s == "*" || s == "/") return true;

        return false;
    }

    int performOperation(int a, int b, string operation) {
        
        if(operation == "+") return a + b;
        
        if(operation == "-") return a - b;
        
        if(operation == "*") return a * b;
        
        return a / b;
    }

    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1) return stoi(tokens[0]);
        stack<int> st;

        for(int i = 0; i < tokens.size() - 1; i++) {
            if(isOperator(tokens[i])) {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                
                st.push(performOperation(operand1, operand2, tokens[i]));
            }else{
                st.push(stoi(tokens[i]));
            }
        }

        int number2 = st.top();
        st.pop();
        int number1 = st.top();
        st.pop();

        int ans = performOperation(number1, number2, tokens[tokens.size() - 1]);

        return ans;
    } 
};
