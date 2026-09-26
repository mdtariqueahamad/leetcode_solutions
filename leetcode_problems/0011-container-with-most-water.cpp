// LeetCode Problem 0011: Container With Most Water
// Difficulty: Medium
// Link: https://leetcode.com/problems/container-with-most-water/
// Language: cpp

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int *prefix = &height[0], *suffix = &height[height.size() - 1];
        while (prefix < suffix) {
            if (area < min(*prefix, *suffix) * (suffix - prefix))
                area = min(*prefix, *suffix) * (suffix - prefix);
            (*prefix < *suffix) ? prefix++ : suffix--;
        }
        return area;
    }
};