class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0, m1 = 0, m2 = 0, m12 = 0, m22 = 0;
        for(auto x : nums){
        sum += x;
        if(!m1 && (x % 3 == 1)) m1 = x;
        else if(!m2 && (x % 3 == 2)) m2 = x;
        else if(!m12 && (x % 3 == 1)) m12 = x;
        else if(!m22 && (x % 3 == 2)) m22 = x;
        }
        if(!(sum % 3)) return sum;
        else if(sum % 3 == 1){
            if(!m1) m1 = m2+m22;
            if((m2 + m22) % 3 == 1) return sum - min(m1,m2+m22);
            else return sum - m1;
        }
        else{
            if(!m2) m2 = m1+m12;
            if((m1+m12) % 3 == 2) return sum - min(m2,m1+m12);
            else return sum - m2;
        }
    }
};
