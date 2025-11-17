class Solution {
public:
    string frequencySort(string s) {
        pair<int, char> np[62];
        int idx = 0;
        for (char c = 'a'; c <= 'z'; c++)
            np[idx++] = {0, c};
        for (char c = 'A'; c <= 'Z'; c++)
            np[idx++] = {0, c};
        for (char c = '0'; c <= '9'; c++)
            np[idx++] = {0, c};
        
        for(auto x:s){
            if(x >= 'a' && x <= 'z') np[x - 'a'].first++;
            else if(x >= 'A' && x <= 'Z') np[26 + (x - 'A')].first++;
            else if(x >= '0' && x <= '9') np[52 + (x - '0')].first++;
        }

        sort(np, np + 62);
        reverse(np, np + 62);
        string s1;
        for(int i = 0; i < 62; i++){
            if(!np[i].first) break;
            for(int j = 0; j < np[i].first; j++)
            s1 += np[i].second;
        }
        return s1;
    }
};
