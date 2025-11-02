class Solution {
    int maxCap(vector<int>& weights, int cap){
        int sum = 0, count = 1;
       for(int i = 0; i < weights.size(); i++){
           if(sum + weights[i] > cap){
            count++;
            sum = 0;
           }
        sum += weights[i];
       }
       return count;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end()), end = 0, min1 = INT_MAX;
        for(int i : weights)
        end += i;

        while(start <= end){
            int mid = (start + end) / 2;
            int out = maxCap(weights, mid);
            if(out > days){
                start = mid + 1;
            }
            else {
                min1 = mid;
                end = mid - 1;
            }
        }
        return min1;
    }
};
