class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> st;

        for (int i = 0; i < asteroids.size(); i++) {

            while (!st.empty() &&
                   st.back() > 0 &&
                   asteroids[i] < 0) {

                if (abs(asteroids[i]) > st.back()) {
                    st.pop_back();
                }
                else if (abs(asteroids[i]) == st.back()) {
                    st.pop_back();
                    asteroids[i] = 0;
                    break;
                }
                else {
                    asteroids[i] = 0;
                    break;
                }
            }

            if (asteroids[i] != 0)
                st.push_back(asteroids[i]);
        }

        return st;
    }
};