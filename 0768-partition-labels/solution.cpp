class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> last(26, -1), ans;

        for(int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;
        
        for(int i = 0, j = 0, start = 0; i < s.size(); i++) {

            j = max(j, last[s[i] - 'a']);

            if(j == i) {
                ans.push_back(j - start+1);
                start = i+1;
            }
        }

        return ans;
    }
};
