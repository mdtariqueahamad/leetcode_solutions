class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int i = 0;

        while(i < chars.size()) {
            char ch = chars[i];
            int count = 0;

            while(i < chars.size() && chars[i] == ch) {
                i++;
                count++;
            }

            chars[idx++] = ch;

            if(count > 1) {
                string s = to_string(count);

                for(char c : s)
                    chars[idx++] = c;
            }
        }
        return idx;
    }
};