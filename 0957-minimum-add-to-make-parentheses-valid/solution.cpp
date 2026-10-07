class Solution {
public:
    int minAddToMakeValid(string s) {

        int extra = 0, depth = 0;

        for(char c: s)
            if('(' == c) depth++;
            else
                !depth ? extra++: depth--;
        
        return extra + depth;
    }
};
