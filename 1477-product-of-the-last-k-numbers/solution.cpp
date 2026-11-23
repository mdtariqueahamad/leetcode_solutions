class ProductOfNumbers {
    vector<int> nums;
public:
    ProductOfNumbers() {
        nums.push_back(1);
    }
    
    void add(int num) {
        
        if(0 == num){
            nums.clear();
            nums.push_back(1);
            return;
        }

        nums.push_back(nums.back()*num);
    }
    
    int getProduct(int k) {

        if(k >= (int)nums.size()) return 0;

        return nums.back() / nums[nums.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
