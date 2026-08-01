class Solution {
public:
    int countValidPrefixes(string s) {
        int count1 = 0, count0 = 0, count = 0;
        for(char x : s){
            if(x == '0') count0++;
            else count1++;
            if(abs(count0-count1) == 1 || count0==count1) count++;
        }
        return count;
    }
};
