#include <random>
class RandomizedSet {
    mt19937 rng{random_device{}()};

    unordered_map<int, int> mpp;
    vector<int> nums;
public:
    RandomizedSet() { }
    
    bool insert(int val) {

        if(mpp.find(val) != mpp.end()) return false;

        nums.push_back(val);
        mpp[val] = nums.size()-1;

        return true;
    }
    
    bool remove(int val) {  

        if(mpp.find(val) == mpp.end()) return false;

        int lastVal = nums.back();
        swap(nums[mpp[val]], nums[nums.size()-1]);
        mpp[lastVal] = mpp[val];

        nums.pop_back();
        mpp.erase(val);

        return true;
    }
    
    int getRandom() {

        uniform_int_distribution<int> dist(0, nums.size() - 1);
        return nums[dist(rng)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
