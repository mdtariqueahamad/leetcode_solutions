class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;

        unordered_map<int,int> mpp;

        for(int x: hand)
            mpp[x]++;
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto it: mpp)
            pq.push(it.first);

        while(!pq.empty()){
            int arr[groupSize];
            if (pq.size() < groupSize) return false;
            for(int i = 0; i < groupSize; i++){
                arr[i] = pq.top();
                pq.pop();
                mpp[arr[i]]--;
            }
            for(int i = 1; i < groupSize; i++){
                if(arr[i]-arr[i-1] != 1) return false;
                if(mpp[arr[i]]) pq.push(arr[i]);
            }
            if(mpp[arr[0]]) pq.push(arr[0]);
        }
        return pq.empty();
    }
};
