class Solution {
public:
    vector<vector<char>> b;
    char next(int r, int c, char z) {
        for (char n = z; n <= '9'; n++) {

            bool ok = true;
            for (int i = 0; i < 9; i++) {
                if (b[r][i] == n || b[i][c] == n) {
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;

            int sr = r - r % 3;
            int sc = c - c % 3;

            for (int i = sr; i < sr + 3; i++) {
                for (int j = sc; j < sc + 3; j++) {
                    if (b[i][j] == n) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) return n;
        }
        return 'x';
    }
    bool sol = false;
    void solve(int row, int col, char n) {
    if (row == 9) {
        sol = true;
        return;
    }

    if (col == 9) {
        solve(row + 1, 0, '1');
        return;
    }

    if (b[row][col] != '.') {
        solve(row, col + 1, '1');
        return;
    }

    char cx = next(row, col, n);

    if (cx == 'x') return;

    b[row][col] = cx;

    solve(row, col + 1, '1');

    if (sol) return;

    b[row][col] = '.';

    solve(row, col, cx + 1);
}

    void solveSudoku(vector<vector<char>>& board) {
        b = board;
        solve(0, 0, '1');
        board = b;
    }
};
