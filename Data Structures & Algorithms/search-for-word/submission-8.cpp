class Solution {
public:
    bool isInBoard(int i, int j, vector<vector<char>>& board) {
        return i >= 0 && i < board.size() &&
               j >= 0 && j < board[0].size();
    }

    bool isWord(int i, int j, int index, string& word,
                vector<vector<char>>& board) {

        if(index == word.size() - 1)
            return true;

        board[i][j] = '#';

        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        for(auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(isInBoard(ni, nj, board) &&
               board[ni][nj] == word[index + 1]) {

                if(isWord(ni, nj, index + 1, word, board)) {
                    board[i][j] = word[index];
                    return true;
                }
            }
        }

        board[i][j] = word[index];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                int ch = board[i][j];

                if(ch == word[0]) {
                    if(isWord(i, j, 0, word, board)) return true;
                }
            }
        }

        return false;
    }
};
