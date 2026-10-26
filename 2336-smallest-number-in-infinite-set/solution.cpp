class SmallestInfiniteSet {
public:
    int curr;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> st;

    SmallestInfiniteSet() {
        curr = 1;
    }

    int popSmallest() {
        if (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            st.erase(x);
            return x;
        }
        return curr++;
    }

    void addBack(int num) {
        if (num < curr && !st.count(num)) {
            pq.push(num);
            st.insert(num);
        }
    }
};