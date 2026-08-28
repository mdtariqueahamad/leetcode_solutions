class Solution {
public:
    vector<vector<char>> board;
    bool check(char c, int row, int col) {

        board[row][col] = '.';

        for(int i = 0; i < 9; i++){
            if(c == board[row][i]) return false;
            if(c == board[i][col]) return false;
        }

        int r = (row / 3) * 3;
        int cl = (col / 3) * 3;

        for(int i = r; i < (r+3); i++)
            for(int j = cl; j < (cl+3); j++)
                if(c == board[i][j]) return false;

        board[row][col] = c;

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        this -> board = board;
        for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++){
            if('.' == board[i][j]) continue;
            if(!check(board[i][j], i, j)) return false;
        }
        return true;
    }
};
