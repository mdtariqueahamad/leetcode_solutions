class Solution {
    static bool fp(vector<int> &a, vector<int> &b) {
        return b[1] > a[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), fp);

        int n = points.size();

        int i = 0, count = 0;

        while(i < n) {
            int temp = points[i][1];

            while(i < n && temp >= points[i][0]) i++;

            count++;
        }

        return count;
    }
};