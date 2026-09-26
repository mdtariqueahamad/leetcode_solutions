// LeetCode Problem 1807: Evaluate the Bracket Pairs of a String
// Difficulty: Medium
// Link: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
// Language: cpp

class Solution {
public:
    string evaluate(string str, vector<vector<string>>& knowledge) {

       unordered_map<string,string> mpp;

       for(auto s: knowledge)
       mpp[s[0]] = s[1];

       string ans, temp;

       char check = false;
       for(char c: str){
            if(c == '('){
                check = true;
                continue;
            } else if(c == ')'){
                if(mpp.find(temp) != mpp.end()){
                    ans += mpp[temp];
                } else ans += '?';
                temp.clear();
                check = false;
                continue;
            }
            if(check){
                temp += c;
            } else
                    ans += c;
       }

       return ans;
    }
};