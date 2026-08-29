class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> subset;
        
        dfs(0, target, subset, candidates, result);
        
        return result;
    }

    void dfs(int ind, int target, vector<int>& subset, const vector<int>& candidates, vector<vector<int>>& result) {
        if(target == 0) {
            result.push_back(subset);
            return;
        }

        for(int i = ind; i < candidates.size(); i++) {
            if(i > ind && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;

            subset.push_back(candidates[i]);
            dfs(i + 1, target - candidates[i], subset, candidates, result);
            subset.pop_back();
        }
    }
};
