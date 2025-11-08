class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        if(x <= 0 && !(n%2)) x = -x;
        else if(x <= 0){
            x = -x;
            res = -1;
        }
        res *= exp(n * log(x));
        return res;
    }
};
