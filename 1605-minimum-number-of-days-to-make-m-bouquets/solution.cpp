class Solution {
public:
bool possible(vector<int>& bloomDay, int m, int k, int day){
    int count = 0, countbloom = 0;
    for(int i = 0; i < bloomDay.size(); i++){
        if(bloomDay[i] <= day){
            count++;
        }
        else{
            countbloom += (count / k);
            count = 0;
        }
    }
    countbloom += (count / k);
    return countbloom >= m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k) return -1;
        auto [minIt, maxIt] = minmax_element(bloomDay.begin(), bloomDay.end());

    int start = *minIt;
    int end  = *maxIt;
        int ans = -1;
        while(start<=end){
            int mid = (start + end) / 2;
            if(possible(bloomDay, m, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return ans;
    }
};
