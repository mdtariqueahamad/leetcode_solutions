// LeetCode Problem 1539: Kth Missing Positive Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/kth-missing-positive-number/
// Language: cpp

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 0;
        for(int i : arr){
            j++;
            while(i != j && k){
                k--;
                if(!k) return j;
                j++;
            }
        }
        while(k){
            k--;
            j++;
        }

        return j;
    }
};