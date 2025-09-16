class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for( int n : nums2){
        nums1.push_back(n);
        }
        if(!is_sorted(nums1.begin(), nums1.end())){
            sort(nums1.begin(), nums1.end());
        }
        int x = nums1.size();
        double n;

        if(!(x%2)){
            x /= 2;
            n = nums1[x--] + nums1[x];
            n/=2;
        }
        else{
            x /= 2;
            n = nums1[x];
        }
        return n;

    }
};
