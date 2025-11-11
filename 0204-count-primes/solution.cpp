class Solution {
public:
    int countPrimes(int n) {
        vector <int> vec(n,1);
        if(n < 2) return 0;
        vec[0] = 0; vec[1] = 0;
        for(int i = 2; i*i < n; i++){
            if(vec[i])
            for(int j = i*i; j < n; j += i){
                vec[j] = 0;
            }
        }
        int count = 0;
        for(int x : vec)
            count += x;
        return count;
    }
};
