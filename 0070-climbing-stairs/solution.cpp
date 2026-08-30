class Solution {
public:
    int arr[46] = {0};
    int helper(int n){
        if(!n || 1 == n) return 1;
        if(arr[n]) return arr[n];
        arr[n] = helper(n-1) + helper(n-2);
        return arr[n];
    }
    int climbStairs(int n) {
        return helper(n);
    }
};
