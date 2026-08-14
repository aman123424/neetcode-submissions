class MinStack {
public:
    stack<int> st;
    stack<int> mini;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(mini.empty()){
            mini.push(val);
        } else {
            mini.push(min(mini.top(), val));
        }
    }
    
    void pop() {
        st.pop();
        mini.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};
