class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> ans;

        for(int x : spells) {

            long long n = (success + x - 1) / x;

            int l = 0, r = potions.size() - 1;
            int i = potions.size();

            while(l <= r) {
                int mid = l + (r - l) / 2;

                if(potions[mid] >= n) {
                    i = mid;
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }

            ans.push_back(potions.size() - i);
        }

        return ans;
    }
};