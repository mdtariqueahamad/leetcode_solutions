class Solution {
public:
    bool isPowerOfThree(int n){
        if(n <= 0) return  false;
        float x = log(n)/log(3);
        return pow(3,x) == n;
    }
};
