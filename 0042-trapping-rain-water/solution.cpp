class Solution {
public:
    int trap(vector<int>& height){
        if(!height.size()) return 0;
        int *lptr = &height[0], *rptr = &height[height.size()-1], lmax = 0, rmax = 0, total = 0;
        while(lptr < rptr){
            lmax = max(lmax, *lptr);
            rmax = max(rmax, *rptr);
            if(*lptr > *rptr){
                total += min(lmax,rmax) - *rptr;
                rptr--;
            } else{
                total += min(lmax,rmax) - *lptr;
                lptr++;
            }
        }
        return total;
    }
};
