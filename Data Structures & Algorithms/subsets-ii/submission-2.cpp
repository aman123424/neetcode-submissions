class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> output;
        set<vector<int>> subsets;

        backtrack(0, output, nums, subsets);

        for(auto it : subsets) {
            res.push_back(it);
        }

        return res;
    }

    void backtrack(int i, vector<int>& output, vector<int>& nums, set<vector<int>>& subsets) {
        if(i == nums.size()) {
            subsets.insert(output);
            return;
        }

        output.push_back(nums[i]);
        backtrack(i + 1, output, nums, subsets);
        output.pop_back();
        backtrack(i + 1, output, nums, subsets);
    }
};
