class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        
        for(auto num : nums) {
            st.insert(num);
        }

        int longest = 0;

        for(int num : nums) {
            if(st.find(num - 1) == st.end()) {
                int length = 1;
                while(st.find(num + length) != st.end()){
                    length++;
                } 
                longest = max(length, longest);
            }
        }

        return longest;
        
    }
};
