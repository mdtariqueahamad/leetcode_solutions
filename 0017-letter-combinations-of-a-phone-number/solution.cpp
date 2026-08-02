class Solution {
public:
    string temp;
    vector<string> ans;
    vector<string> help = {"","", "abc", "def",
                            "ghi", "jkl", "mno",
                            "pqrs", "tuv", "wxyz"};
    void func(string s, int sidx, int hidx){
        if(s.size() == sidx){
            ans.push_back(temp);
            return;
        }
        if(help[s[sidx]-'0'].size() == hidx) return;
        temp += help[s[sidx]-'0'][hidx];
        func(s, sidx+1, 0);
        temp.pop_back();
        func(s, sidx, hidx+1);
    }

    vector<string> letterCombinations(string digits) {
        func(digits, 0, 0);
        return ans;
    }
};
