// LeetCode Problem 0215: Kth Largest Element in an Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Language: cpp

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int x: nums){
            if(k){
                pq.push(x);
                k--;
            } else 
                if(pq.top() < x){
                    pq.pop();
                    pq.push(x);
                }
        }

        return pq.top();
    }
};