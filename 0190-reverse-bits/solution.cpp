class Solution {
public:
    int reverseBits(int n) {
        int rev = 0;
        for(int i=0 ; n ; i++){
            if(n&1){
                rev += 1<<(31-i);
            }
            n >>= 1;
        }
        return rev;

    }
};

