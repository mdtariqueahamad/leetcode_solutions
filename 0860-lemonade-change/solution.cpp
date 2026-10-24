class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int doll[3] = {0};

        for(int x: bills) {
            doll[x/10]++;
            if(10 == x) {
                if(doll[0] > 0)
                    doll[0]--;
                else return false;
            }
            else if(20 == x) {

                if(doll[0] > 0 && doll[1] > 0) {
                    doll[0]--;
                    doll[1]--;
                } else if(doll[0] > 2) doll[0] -= 3;

                else return false;
            }
        }

        return true;
    }
};