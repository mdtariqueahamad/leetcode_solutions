class Solution {
public:
long long kcal(long long n, vector<int>& piles){
    long long k = 0;
    for(int i = 0; i < piles.size(); i++){
        if(piles[i]%n){
            k += ((piles[i]/n)+1);
        }
        else k += piles[i]/n;
    }
    return k;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        long long largest = *max_element(piles.begin(),piles.end());
        long long start = 1, end = largest;
        int ans;
        while(start <= end){
            long long mid = (start+end)/2;
            long long k = kcal(mid, piles);
            if(k <= h){
                end = mid - 1;
                ans = mid;
            }
            else start = mid + 1;
        }
        return ans;
    }
};
