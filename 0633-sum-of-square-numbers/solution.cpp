class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low = 0, high = sqrt(c);
        while(low <= high){
            long long sum = pow(low,2) + pow(high,2);
            if(sum == c) return true;
            else if(sum > c) high--;
            else low++;
        }
        return false;
    }
};
