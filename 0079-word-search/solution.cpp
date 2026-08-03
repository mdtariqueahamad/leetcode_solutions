class Solution {
public:
    vector<vector<char>> b;
    string w;
    bool func(int i, int j, int idx){
        if(w.size() == idx) return true;
        if(i < 0 || j < 0 || i == b.size() || j == b[i].size()) return false;
        if(b[i][j] == '$') return false;
        if(b[i][j] == w[idx]) idx++;
        else return false;
        char c = b[i][j];
        b[i][j] = '$';
        bool found = func(i, j+1, idx) ||
                     func(i+1, j, idx) ||
                     func(i, j-1, idx) ||
                     func(i-1, j, idx);
        b[i][j] = c;
        return found;
    }
    bool scan(int i, int j){
        if(i == b.size()) return false;
        bool x = func(i, j, 0);
        if(x) return true;
        if(j == b[i].size()-1) return scan(i+1, 0);
        return scan(i, j+1);
    }
    bool exist(vector<vector<char>>& board, string word) {
        b = board, w = word;
        return scan(0, 0);
    }
};
