class Solution {
public:
    int minFlips(int a, int b, int c) {

        int ans = 0;

        for(int i = 1; i <= INT_MAX/2; i <<= 1)

            if(i&c && !((a|b)&i)) ans++;
            else if(!(c&i)){
                if(a&i) ans++;
                if(b&i) ans++;
            }

        return ans;
    }
};