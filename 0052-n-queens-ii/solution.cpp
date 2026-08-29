class Solution {
public:
    int count = 0, size;
    vector<string> board;
    void cross(int n, int m){
        for(int i = 0; i < size; i++){
            board[n][i] = 'x';
            board[i][m] = 'x';
        }
        int N = n, M = m;
        while(n >= 0 && m >= 0)
            board[n--][m--] = 'x';
        
        n = N + 1, m = M + 1;
        while(n < size && m < size)
            board[n++][m++] = 'x';

        n = N - 1, m = M + 1;
        while(n >= 0 && m < size)
        board[n--][m++] = 'x';

        n = N + 1, m = M - 1;
        while(n < size && m >= 0)
        board[n++][m--] = 'x';
    }
    void helper(int row, int col, int queen){
        if(row == size){
            if(queen == size) count++;
            return;
        }
        if(size <= col) return;
        if('x' == board[row][col]){
            helper(row, col+1, queen);
            return;
        }
        vector<string> old = board;
        board[row][col] = 'Q';
        cross(row, col);
        helper(row+1, 0, queen+1);
        board = old;
        helper(row, col+1, queen);
    }
    int totalNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        size = n;
        helper(0, 0, 0);
        return count;
    }
};
