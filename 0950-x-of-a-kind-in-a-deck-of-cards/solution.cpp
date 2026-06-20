class Solution {
public:
    int gcd(int num1, int num2){
        if(!(num2 % num1)) return num1;
        return gcd(num2 % num1, num1);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mpp;
        for(int x : deck)
        mpp[x]++;

        int ans = mpp[deck[0]];
        for(auto it: mpp){
            ans = gcd(ans, it.second);
        }
        return ans > 1;
    }
};
