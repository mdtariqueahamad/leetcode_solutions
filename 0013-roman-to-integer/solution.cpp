class Solution {
public:
    int romanToInt(string s) {
        int res = 0, temp = 0, n;
        for(char c: s){
        switch(c){
            case 'I':
            n = 1;
            break;

            case 'V':
            n = 5;
            break;

            case 'X':
            n = 10;
            break;

            case 'L':
            n = 50;
            break;

            case 'C':
            n = 100;
            break;

            case 'D':
            n = 500;
            break;

            case 'M':
            n = 1000;
            break;
        }
        if(temp<n){
            res -= temp;
            n -= temp;
            res += n;
        }
        else{
            res += n;
        }

        temp = n;
    }
    return res;
    }
};
