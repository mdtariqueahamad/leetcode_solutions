class Solution {
public:
    string reverseStr(string s, int k){
    for(int j = 0; j < s.size(); j += 2*k){
    int left = j;
    int right = min(j + k - 1, (int)s.size() - 1);
    while(left < right)
        swap(s[left++], s[right--]);
    }
        return s;
    }
};
