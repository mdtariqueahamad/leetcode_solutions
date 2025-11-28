class Solution {
public:
    bool isHappy(int n) {
        while(n>4){
            int m = n;
            n = 0;
            while(m){
                n += pow(m%10,2);
                m /= 10;
            }
        }
        return n == 1;
    }
};
