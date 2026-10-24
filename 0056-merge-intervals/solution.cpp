class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;

        for(int i = 0; i < intervals.size(); i++) {

            vector<int> temp(2);
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];

            while(i < intervals.size()-1 && 
            temp[1] >= intervals[i+1][0])
            {
                temp[1] = max(temp[1], intervals[i+1][1]);
                i++;
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
