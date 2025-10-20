class Solution {
public:
    string convert(string s, int num) {
        vector<string> vec(num);
        if(num==1){return s;}
        int n = 0;
        while(n<s.size()){
            int i = 0;
        for(i = 0; i<num; i++){
            if(n>=s.size()) break;
            vec[i].push_back(s[n]);
            n++;
        }
        for(i=num-2;i>0;i--){
            if(n>=s.size()) break;
            vec[i].push_back(s[n]);
            n++;
        }
        }
        s = "";
        for(auto idk:vec){
            s += idk;
        }

        return s;
    }
};
