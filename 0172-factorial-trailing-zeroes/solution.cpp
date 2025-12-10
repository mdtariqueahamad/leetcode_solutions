class Solution {
public:
    int trailingZeroes(int n) {
        int zero = 0;
        for(int i = 5; n / i ; i *= 5)
        zero += n / i;
        return zero;
    }
};
