class Solution {
public:
    bool canAliceWin(int n) {
        
        int x = 10;

        while(x) {

            if(n < x) return x & 1;

            n -= x;
            x--;
        }

        return true;
    }
};
