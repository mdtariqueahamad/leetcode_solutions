class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, n = matrix.size(),
        m = matrix[0].size(), high = m * n - 1;
        while(low <= high){
            int mid = ((long long)high + low) / 2;
            int row = mid / m;
            int col = mid % m;
            if(target == matrix[row][col]) return true;
            else if(matrix[row][col] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
