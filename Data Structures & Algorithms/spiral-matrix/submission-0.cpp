class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int m = matrix.size();
        int n = matrix[0].size();

        int firstRow = 0, firstCol = 0;
        int lastRow = m, lastCol = n;

        while(firstRow < lastRow && firstCol < lastCol) {
            
            for(int ind = firstCol; ind < lastCol; ind++) {
                result.push_back(matrix[firstRow][ind]);
            }
            firstRow++;

            for(int ind = firstRow; ind < lastRow; ind++) {
                result.push_back(matrix[ind][lastCol - 1]);
            }
            lastCol--;

            if(!(firstCol < lastCol && firstRow < lastRow)) {
                break;
            }

            for(int ind = lastCol - 1; ind >= firstCol; ind--) {
                result.push_back(matrix[lastRow - 1][ind]);
            }
            lastRow--;
            
            for(int ind = lastRow - 1; ind >= firstRow; ind--) {
                result.push_back(matrix[ind][firstCol]);
            }
            firstCol++;
        }

        return result;
    }
};
