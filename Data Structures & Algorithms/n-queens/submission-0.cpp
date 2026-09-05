class Solution {
public:
    vector<bool> cols;
    vector<bool> diag1;
    vector<bool> diag2;

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.'));

        cols.resize(n, false);
        diag1.resize(2 * n - 1, false);
        diag2.resize(2 * n - 1, false);

        backtrack(0, curr, n, ans);

        return ans;
    }

    void backtrack(int rowInd, vector<string>& curr, int n,
                   vector<vector<string>>& ans) {

        if(rowInd == n) {
            ans.push_back(curr);
            return;
        }

        for(int colInd = 0; colInd < n; colInd++) {

            if(cols[colInd] ||
               diag1[rowInd + colInd] ||
               diag2[rowInd - colInd + n - 1]) {
                continue;
            }

            cols[colInd] = true;
            diag1[rowInd + colInd] = true;
            diag2[rowInd - colInd + n - 1] = true;

            curr[rowInd][colInd] = 'Q';

            backtrack(rowInd + 1, curr, n, ans);

            curr[rowInd][colInd] = '.';

            cols[colInd] = false;
            diag1[rowInd + colInd] = false;
            diag2[rowInd - colInd + n - 1] = false;
        }
    }
};
