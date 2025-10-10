class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        if(digits[n]==9){
        while(n>=0 && digits[n]==9){
            digits[n] = 0;
            n--;
        }
        if(n == -1){
            digits.insert(digits.begin(),1);
        }
        else{
            ++digits[n];
        }
        }
        else{
            ++digits[n];
        }
        return digits;
    }
};
