class Solution {
public:
    void dfs(int i, vector<vector<int>>& result, vector<int>& currSubset, vector<int>& nums)  {
        if(i >= nums.size()) {
            result.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[i]);
        dfs(i + 1, result, currSubset, nums);
        currSubset.pop_back();
        dfs(i + 1, result, currSubset, nums);  
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currSubset;

        dfs(0, result, currSubset, nums);

        return result;


    }
};
