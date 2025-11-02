class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 0;
        for(int i : arr){
            j++;
            while(i != j && k){
                k--;
                if(!k) return j;
                j++;
            }
        }
        while(k){
            k--;
            j++;
        }

        return j;
    }
};
