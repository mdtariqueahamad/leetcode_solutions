class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        if(n == INT_MIN) return false;
        return !(n & n-1);
    }
};
