class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.size()) return 0;
        if(needle.size() > haystack.length()) return -1;
        char *str = &haystack[0], *nptr = &needle[0];
        while(str <= &haystack[haystack.size()-needle.size()]){
            if(*str == *nptr){
            string check = haystack.substr(str-&haystack[0], needle.size());
            if(check == needle) return str-&haystack[0];
            }
            str++;
        }
        return -1;
    }
};
