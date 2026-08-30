class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<bool> pick(nums.size(), false);
        vector<vector<int>> result;

        backtracking(curr, pick, nums, result);

        return result;
    }

    void backtracking(vector<int>& curr, vector<bool>& pick, vector<int>& nums, vector<vector<int>>& result) {
        if(curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(pick[i]) continue;

            if(i > 0 && nums[i] == nums[i - 1] && !pick[i - 1]) continue;

            pick[i] = true;
            curr.push_back(nums[i]);
            backtracking(curr, pick, nums, result);
            curr.pop_back();
            pick[i] = false;
        }
    }
};