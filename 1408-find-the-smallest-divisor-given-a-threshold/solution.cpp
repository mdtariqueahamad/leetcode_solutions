class Solution {
    int div(vector <int> &nums, int mid){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += ceil((double)nums[i]/mid);
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1, end = *max_element(nums.begin(),nums.end()), min1 = INT_MAX;
        while(start <= end){
            int mid = (start + end) / 2;
            int cal = div(nums,mid);
            if(cal <= threshold){
                end = mid - 1;
                min1 = min(mid,min1);
            }
            else start = mid + 1;
        }
        return min1;
    }
};
