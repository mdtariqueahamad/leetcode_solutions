class Solution {
public:
    int fib(int n) {
        int n1 = 0, n2 = 1, temp;
        if(n == 0 || n == 1){
            (n == 0) ? temp = n1 : temp = n2;
        }
        for(int i = 2; i <= n; i++){
            temp = n2 + n1;
            n1 = n2;
            n2 = temp;
        }
        return temp;
    }
};
