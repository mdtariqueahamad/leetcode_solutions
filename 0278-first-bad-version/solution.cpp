// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    int bs(int n) {
        int x = n;

        int l = 1;
        while (l < x) {
            int mid = l + (x-l) / 2;
            if(isBadVersion(mid)) x = mid;
            else l = mid + 1;
        }

        return x;
    }
public:
    int firstBadVersion(int n) {
        return bs(n);
    }
};
