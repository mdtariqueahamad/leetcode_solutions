class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        if(!n) return 1;
        x %= MOD;
        if(n&1) return (x * power(x, n-1)) % MOD;

        return power(x*x,n >> 1) % MOD;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};
