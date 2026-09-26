// LeetCode Problem 0048: Rotate Image
// Difficulty: Medium
// Link: https://leetcode.com/problems/rotate-image/
// Language: cpp

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i = 0; i < row-1; i++)
            for(int j = i+1; j < row; j++)
                swap(matrix[i][j],matrix[j][i]);

        for(int i = 0; i < row; i++)
        reverse(matrix[i].begin(),matrix[i].end());
    }
};