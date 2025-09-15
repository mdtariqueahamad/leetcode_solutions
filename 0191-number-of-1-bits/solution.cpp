class Solution {
public:
    int hammingWeight(int n) {
        int c=0;
        while(n){
            if(n%2)
                c++;
            n/=2;
        }
        return c;
    }
};
