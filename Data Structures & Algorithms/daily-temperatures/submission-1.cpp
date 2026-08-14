class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<pair<int, int>> st;
        
        for(int i = 0; i < n; i++) {
            int currTemp = temperatures[i];

            while(!st.empty() && currTemp > st.top().first) {
                auto pair = st.top();
                st.pop();
                result[pair.second] = i - pair.second; 
            }

            st.push({currTemp, i});
        }

        return result;
    }
};
