class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMost(n, -1);
        vector<int> rightMost(n, n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if(!st.empty()) {
                leftMost[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if(!st.empty()) {
                rightMost[i] = st.top();
            }

            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            leftMost[i] += 1;
            rightMost[i] -= 1;
            maxArea = max(maxArea, heights[i] * (rightMost[i] - leftMost[i] + 1)); 
        }

        return maxArea;
    }
};
