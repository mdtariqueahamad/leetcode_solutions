class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char,string> mpp;
        unordered_map<string,char> mpp2;

        vector<string> v;

        int i = 0;
        while(i < s.length()){

            while (i < s.length() && s[i] == ' ') i++;

            if(i >= s.length()) break;
            
            string temp;
            while(i < s.length() && s[i] != ' ') temp += s[i++];

            v.push_back(temp);
        }

        i = 0;

        if(pattern.size() != v.size()) return false;

        for(char c: pattern){
            if(mpp.find(c) != mpp.end()) {
                if(mpp[c] != v[i]) return false;
            } 
            else if(mpp2.find(v[i]) != mpp2.end()){
                return false;
            }
            else{
                mpp[c] = v[i];
                mpp2[v[i]] = c;
            }
            i++;
        }

        return true;
    }
};