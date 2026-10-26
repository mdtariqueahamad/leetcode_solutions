class Solution {
public:
    long long totalCost(auto& A, int k, int candidates) {
        int n = A.size();
        if (candidates * 2 + k > n) {
            ranges::nth_element(A, A.begin() + k);
            return accumulate(A.begin(), A.begin() + k, 0LL);
        }

        priority_queue<int, vector<int>, greater<>> pre, suf;
        for (int i = 0; i < candidates; i++) {
            pre.push(A[i]);
            suf.push(A[n - 1 - i]);
        }

        long long res = 0;
        int i = candidates, j = n - 1 - candidates;

        while (k--) {
            if (pre.top() <= suf.top()) {
                res += pre.top();
                pre.pop();
                pre.push(A[i++]);
            } else {
                res += suf.top();
                suf.pop();
                suf.push(A[j--]);
            }
        }

        return res;
    }
};