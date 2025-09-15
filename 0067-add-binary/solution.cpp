
class Solution {
public:
    string addBinary(string s1, string s2) {
        int j = s2.size();
        int i = s1.size();
        int sum = 0;
        int bit;
        string s3 = "";
        while(i || j|| sum){
            if(i){
                i--;
            sum += s1[i] -'0';
            }
            if(j){
                j--;
            sum += s2[j] - '0';
            }
            bit = sum % 2;
            s3.push_back(bit + '0');
            sum /= 2;
        }
        reverse (s3.begin(),s3.end());
        return s3;
    }
};
