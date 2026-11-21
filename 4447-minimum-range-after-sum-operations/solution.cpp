class Solution {
public:
    int minRange(int a, int b, int c) {

        return min(max({a,b,c}) - min({a,b,c}), a + b + c - max({a,b,c}) - min({a,b,c}));
    }
};
