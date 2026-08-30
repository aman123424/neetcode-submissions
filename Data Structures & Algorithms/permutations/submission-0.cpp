class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> currPerm;
        vector<bool> pick(nums.size(), false);
        vector<vector<int>> result;

        backtracking(currPerm, nums, pick, result);

        return result;
    }

    void backtracking(vector<int>& currPerm, const vector<int>& nums, vector<bool>& pick, vector<vector<int>>& result) {
        if(currPerm.size() == nums.size()) {
            result.push_back(currPerm);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!pick[i]) {
                pick[i] = true;
                currPerm.push_back(nums[i]);
                backtracking(currPerm, nums, pick, result);
                currPerm.pop_back();
                pick[i] = false;
            }
        }
    }
};
