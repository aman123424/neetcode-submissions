class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;

        int score = 0;

        for(int i = 0; i < operations.size(); i++) {
            string operation = operations[i];

            if(operation == "C") {
                st.pop_back();
            } else if(operation == "D") {
                int curr = st.back();
                st.push_back(curr * 2);
            } else if(operation == "+"){
                int prev = st.back();
                int prev2 = st[st.size() - 2];
                st.push_back(prev + prev2);
            } else {
                st.push_back(stoi(operation));
            }
        }

        for(int i = 0; i < st.size(); i++) {
            score += st[i];
        }

        return score;
    }
};