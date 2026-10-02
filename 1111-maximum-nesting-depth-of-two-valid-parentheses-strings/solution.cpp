class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        vector<int> ans;
        int temp = 0;

        for(char c: seq){

            if(c == '(') temp++;

            ans.push_back(temp & 1);

            if(c == ')') temp--;
        }

        return ans;
    }
};