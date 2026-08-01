class Solution {
public:
    double func(double x, long long n){
        if(!n) return 1;
        if(n&1) return x * func(x, n-1);
        return func(x*x, n/2);
    }
    double myPow(double x, int n) {
        if(n < 0){
            long long N = n;
            return 1 / func(x, -N);
        }
        return func(x, n);
    }
};
