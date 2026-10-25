class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        int low = 0, high = 1, count = 0;

        while(high < n)

            if(intervals[low][1] <= intervals[high][0]) {
                low = high;
                high++;
            } else if(intervals[low][1] <= intervals[high][1]) {
                high++;
                count++;
            } else if(intervals[low][1] > intervals[high][1]) {
                low = high;
                high++;
                count++;
            }

        return count;
    }
};