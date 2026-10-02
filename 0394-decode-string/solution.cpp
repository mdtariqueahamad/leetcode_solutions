class Solution {
public:

    string decode(string& s, int& i) {

        string result = "";
        int num = 0;

        while (i < s.size() && s[i] != ']') {

            if (isdigit(s[i])) {

                num = 0;

                while (isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                i++; // skip '['

                string temp = decode(s, i);

                i++; // skip ']'

                while (num--) {
                    result += temp;
                }

            }
            else {
                result += s[i];
                i++;
            }
        }

        return result;
    }

    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};