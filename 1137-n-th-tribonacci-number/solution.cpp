class Solution {
public:
    vector<int> trib = {0, 1, 1};

    int helper(int n) {

        if (trib[n] != -1) return trib[n];

        trib[n] = helper(n-1) + helper(n-2) + helper(n-3);

        return trib[n];
    }

    int tribonacci(int n) {

        trib.resize(n+1, -1);

        helper(n);

        return trib[n];
    }
};