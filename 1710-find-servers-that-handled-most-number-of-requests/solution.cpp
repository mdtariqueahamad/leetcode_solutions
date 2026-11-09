class Solution {
    typedef pair<int, int> p;
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        vector<int> freq(k, 0);
        set<int> freeServers;
        priority_queue<p, vector<p>, greater<p>> busyServers;

        for(int i = 0; i < k; i++)
            freeServers.insert(i);

        for(int i = 0; i < load.size(); i++) {

            while(!busyServers.empty() && busyServers.top().first <= arrival[i]) {

                freeServers.insert(busyServers.top().second);
                busyServers.pop();

            }

            if(freeServers.empty()) continue;

            auto nx = freeServers.lower_bound(i%k);

            if(nx == freeServers.end()) nx = freeServers.begin();

            int availServer = *nx;

            busyServers.push({arrival[i]+load[i], availServer});
            freeServers.erase(availServer);
            freq[availServer]++;
        }

        vector<int> ans;

        int largest = *max_element(freq.begin(), freq.end());

        for(int i = 0; i < freq.size(); i++)
            if(largest == freq[i]) ans.push_back(i);

        return ans;
    }
};
