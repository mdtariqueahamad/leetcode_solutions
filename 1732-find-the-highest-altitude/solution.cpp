class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        gain.insert(gain.begin(), 0);

        int mx = 0;

        for(int i = 1; i < gain.size(); i++){
            gain[i] = gain[i] + gain[i-1];
            mx = max(mx, gain[i]);
        }

        return mx;
    }
};