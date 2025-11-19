class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = bits.size() - 2;
        int count = 0;
        while (i >= 0 && bits[i] == 1) {
            count++;
            i--;
        }
        return (count % 2 == 0);
    }
};

