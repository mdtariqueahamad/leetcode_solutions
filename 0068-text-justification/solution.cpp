class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> ans;

        for(int i = 0; i < words.size(); ) {
            
            int len = words[i].length(), j = i+1, spc = 0;

            while(j < words.size() &&
            1 + spc + words[j].length() + len <= maxWidth) {

                len += words[j].length();
                spc++; j++;
            }

            string s;

            if(spc == 0) {
                s += words[i++];
                s.append(maxWidth-s.length(), ' ');
                ans.push_back(s);
                continue;
            }

            if(j == words.size()) {

                while(i < j) {
                    s += words[i];
                    if(spc) {
                        s += " ";
                        spc--;
                    }
                    i++;
                }
                s.append(maxWidth-s.length(), ' ');
                ans.push_back(s);
                break;
            }

            int n = spc;
            spc = maxWidth - len;
            int mod = spc % n;
            spc /= n;

            while(i < j) {

                s += words[i];

                if(mod) {
                    s += " ";
                    mod--;
                }

                if(s.length() < maxWidth)
                s.append(spc, ' ');
                i++;
            }

            ans.push_back(s);
        }

        return ans;
    }
};
