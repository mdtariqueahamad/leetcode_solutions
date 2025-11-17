class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
                unordered_map<int,int> map;
            for(int j = i; j < s.size(); j++){
                map[s[j]]++;
                int Max = 0, Min = INT_MAX; 
                for(auto x : map){
                    Max = max(Max,x.second);
                    Min = min(Min,x.second);
                }
                sum += (Max-Min);
            }
        }
        return sum;
    }
};
