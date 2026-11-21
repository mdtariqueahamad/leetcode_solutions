class Solution {
public:
    vector<string> assignUmbrella(vector<int> &rain) {

        int alice = 0, bob = 0;
        vector<string> ans(rain.size());

        for(int i = 0; i < rain.size(); i++) {

            if(rain[i] == 1 && i+1 < rain.size() && rain[i] == rain[i+1]) {
                ans[i] = alice <= bob? "Alice": "Bob";

                if(ans[i] == "Alice") alice++;
                else bob++;
            } else if(rain[i] == 1) {
                ans[i] = "Bob";
                bob++;
            } else {
                ans[i] = "None";
            }
        }

        return ans;
    }
};
