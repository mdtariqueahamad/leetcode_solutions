class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> vec(m+n);
        int *ptr1 = nums1.data(), *ptr2 = nums2.data(),
        *end1 = nums1.data() + m, *end2 = nums2.data() + n;
        for(int i = 0; i < (m+n); i++){
            if(ptr2 == end2 || (ptr1 != end1 && *ptr1 <= *ptr2))
            vec[i] = *ptr1++;
            else vec[i] = *ptr2++;
        }
        nums1 = vec;
    }
};
