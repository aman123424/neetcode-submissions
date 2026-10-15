class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;

        int score = 0;

        for(int i = 0; i < operations.size(); i++) {
            string operation = operations[i];

            if(operation == "C") {
                score -= st.back();
                st.pop_back();
            } else if(operation == "D") {
                int curr = st.back();
                st.push_back(curr * 2);
                score += st.back();
            } else if(operation == "+"){
                int prev = st.back();
                int prev2 = st[st.size() - 2];
                st.push_back(prev + prev2);
                score += st.back();
            } else {
                st.push_back(stoi(operation));
                score += stoi(operation);
            }
        }

        return score;
    }
};