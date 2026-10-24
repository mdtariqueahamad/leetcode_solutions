class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gi = 0, si = 0, count = 0;
        while(gi < g.size() && si < s.size()) {
            if(g[gi] <= s[si]) {
                count++;
                gi++;
                si++;
            }
            else si++;
        }

        return count;
    }
};