class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++) {
            int start = i;
            while(!st.empty() && st.top().second > heights[i]) {
                pair<int, int> top = st.top();
                int index = top.first;
                int height = top.second;
                maxArea = max(maxArea, height * (i - index));
                start = index;
                st.pop();
            }
            st.push({ start, heights[i] });
        }

        while(!st.empty()) {
            int index = st.top().first;
            int height = st.top().second;
            maxArea = max(maxArea, height * (n - index));
            st.pop();
        }

        return maxArea;
    }
};
