class Solution{
    void radixSort(vector<int>& v) {
    int n = v.size();
    if (n <= 1) return;
    int maxVal = *max_element(v.begin(), v.end());

    for (long long exp = 1; maxVal / exp > 0; exp *= 10) {
        vector<int> output(n);
        int count[10] = {0};

        for (int i = 0; i < n; i++)
            count[(v[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            int digit = (v[i] / exp) % 10;
            output[count[digit] - 1] = v[i];
            count[digit]--;
        }

        for (int i = 0; i < n; i++)
            v[i] = output[i];
    }
}
public:
    int maximumGap(vector<int>& nums) {
        radixSort(nums);
        int maxdiff = 0;
        for(int i = 1; i < nums.size(); i++){
            int diff = nums[i] - nums[i-1];
            maxdiff = max(maxdiff, diff);
        }
        return maxdiff;
    }
};
