// LeetCode Problem 3483: Unique 3-Digit Even Numbers
// Difficulty: Easy
// Link: https://leetcode.com/problems/unique-3-digit-even-numbers/
// Language: cpp

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> st;

        int n = digits.size();

        for(int i = 0; i < n; i++) {          // units
            if(digits[i] & 1)
                continue;

            for(int j = 0; j < n; j++) {      // tens
                if(j == i)
                    continue;

                for(int k = 0; k < n; k++) {  // hundreds
                    if(k == i || k == j)
                        continue;

                    if(digits[k] == 0)
                        continue;

                    int num = digits[k] * 100
                            + digits[j] * 10
                            + digits[i];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};