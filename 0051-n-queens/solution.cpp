class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    int size;
    void solve(int i, int j, int nq){
        if(i == size){
            if(size == nq) ans.push_back(temp);
            return;
        }
        if(j >= size) return;
        if(temp[i][j] == '.') {
            solve(i, j+1, nq);
            return;
        }
        vector<string> old = temp;
        cross(i, j);
        temp[i][j] = 'Q';
        nq++;
        solve(i+1, 0, nq);
        nq--;
        temp = old;
        solve(i, j+1, nq);
    }
    void cross(int n, int m){
        for(int i = 0; i < size; i++){
            temp[n][i] = '.';
            temp[i][m] = '.';
        }
        int N = n, M = m;
        while(n >= 0 && m >= 0)
            temp[n--][m--] = '.';
        
        n = N + 1, m = M + 1;
        while(n < size && m < size)
            temp[n++][m++] = '.';

        n = N - 1, m = M + 1;
        while(n >= 0 && m < size)
        temp[n--][m++] = '.';

        n = N + 1, m = M - 1;
        while(n < size && m >= 0)
        temp[n++][m--] = '.';
    }
    
    vector<vector<string>> solveNQueens(int n) {
        temp = vector<string>(n, string(n,'x'));
        size = n;
        solve(0,0,0);
        return ans;
    }
};
