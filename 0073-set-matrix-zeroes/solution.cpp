class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool row0 = false, col0 = false;

        // Step 1: check if first row and first col have 0
        for(int i = 0; i < rows; i++)
            if(matrix[i][0] == 0) col0 = true;

        for(int j = 0; j < cols; j++)
            if(matrix[0][j] == 0) row0 = true;

        // Step 2: mark zeros in first row and col
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 3: set zeros using marks
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Step 4: handle first row/col
        if(row0)
            for(int j = 0; j < cols; j++) matrix[0][j] = 0;

        if(col0)
            for(int i = 0; i < rows; i++) matrix[i][0] = 0;
    }
};
