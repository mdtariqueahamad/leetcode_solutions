class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalCost = 0, ans = 0, total = 0;

        for(int i = 0; i < gas.size(); i++) {
            totalCost += gas[i] - cost[i];

            total += gas[i] - cost[i];

            if(total < 0) {
                total = 0;
                ans = i+1;
            }
        }

        return (totalCost < 0)? -1: ans;
    }
};
