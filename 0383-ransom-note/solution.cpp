class Solution {
public:
    bool canConstruct(string r, string m) {
       int arr[26] = {0};
       for(auto c : m)
       arr[c - 'a']++;

       for(auto c : r)
       arr[c - 'a']--;

       for(auto x : arr)
       if(x < 0) return false;

       return true;
    }
};
