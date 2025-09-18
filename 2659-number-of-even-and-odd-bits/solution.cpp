class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        for(int i = 0; n ; i++){
            if(n&1 && i%2){
                odd++;
            }
            else if(n&1 && !(i%2)){
                even++;
            }
            n >>= 1;
        }
        return {even,odd};
    }
};
