class Solution {
public:
    int maxDepth(string s) {
        int currCount = 0, count = 0;
        for(auto x : s){
            if(x == '(') currCount++;
            else if(x == ')'){
                count = max(currCount,count);
                currCount--;
            }
        }
        return count;
    }
};
