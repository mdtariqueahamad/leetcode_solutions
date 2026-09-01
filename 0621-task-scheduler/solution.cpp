class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> mpp;
        for(auto x: tasks)
            mpp[x]++;
        
        vector<int> temp(mpp.size());
        auto x = temp.begin();

        for(auto it: mpp){
            *x = it.second;
            x++;
        }
        
        sort(temp.begin(), x, greater<int>());

        int time = 0;

        while(!temp.empty()){

            int cycle = n+1;
            int sz = temp.size();

            int i = 0;
            for(; i<sz && cycle; i++){
                temp[i]--;
                cycle--;
            }

            time += (i - 0);

            if(!cycle) sort(temp.begin(), temp.end(), greater<int>());

            while(!temp.empty() && !temp.back())
            temp.pop_back();

            if(!temp.empty()) time += cycle;
        }
        
        return time;
    }
};
