class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum == 0) {
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;
                    while(nums[j] == nums[j - 1] && j < k) j++;
                } else if(sum < 0) {
                    j++;
                } else{
                    k--;
                }
            }
        }

        vector<vector<int>> result;

            for(auto it : st) {
                result.push_back(it);
            }

            return result;
    }
};
