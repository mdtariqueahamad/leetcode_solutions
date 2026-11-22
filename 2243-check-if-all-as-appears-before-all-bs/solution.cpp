class Solution {
public:
    bool checkString(string s) {
        
        int prevB = -1;

        for(int i = 0; i < s.size(); i++)
            if('a' == s[i] && -1 != prevB)
                return false;
            else if('b' == s[i])
                prevB = i;

        return true;
    }
};
