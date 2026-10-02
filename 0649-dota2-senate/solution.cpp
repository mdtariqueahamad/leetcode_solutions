class Solution {
public:
    string predictPartyVictory(string s) {
        
        char senator;
        int sum = 0;

        for(char c: s)
            if('R' == c) sum++;
            else sum += 2;

        for(int i = 0; ;i++) {

            i %= s.size();

            senator = s[i];

            int j = (i+1) % s.size();

            if(s.size() == sum) return "Radiant";
            else if(s.size()*2 == sum) return "Dire";

            while(s[j] == senator) {
                j++;
                j %= s.size();
            }

            if('R' == s[j]) sum--;
            else sum -= 2;

            s.erase(s.begin()+j);

            if (j < i) i--;

        }
        return "lmd";
    }
};