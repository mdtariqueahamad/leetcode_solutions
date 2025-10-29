class Solution {
public:
    int smallestNumber(int n) {
        int m = n * 2;
        int x = 1;
        while(m/=2){
            n |= x;
            x = x << 1;
        }
        return n;
    }
};
