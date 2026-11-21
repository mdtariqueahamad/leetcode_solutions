#define OFFSET 1'000'000'000
#define good_cast(num) (static_cast<size_t>(num) + OFFSET)
#define has(num) (bitmap[good_cast(num) >> 6] & (1ull << (good_cast(num) & 63)))
#define up(num) bitmap[good_cast(num) >> 6] |= (1ull << (good_cast(num) & 63))
#define down(num) bitmap[good_cast(num) >> 6] ^= (1ull << (good_cast(num) & 63))
#define clear(nums, L, r) for (;L<=r;L++) bitmap[good_cast(nums[L]) >> 6] = 0

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        constexpr size_t input_space_sz = 2'000'000'001;
        constexpr size_t nb_ull = (input_space_sz + 63) / 64;
        static std::unique_ptr<uint64_t[]> bitmap(new uint64_t[nb_ull]);

        int n = nums.size();

        // L r
        int L = 0, r = 0;
        // init
        for (; r < min(k + 1, n); r++) {
            int num = nums[r];
            if (has(num)) {
                clear(nums, L, r);
                return true;
            }
            up(num);
        }

        r--;

        while (r + 1 < n) {
            down(nums[L]);
            L++; r++;
            if (has(nums[r])) {
                clear(nums, L, r);
                return true;
            }
            up(nums[r]);
        }

        clear(nums, L, r);
        return false;
    }
};
