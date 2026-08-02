class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void func(int num, int target, int &k){
        if(target == 0 && k == temp.size()){
            ans.push_back(temp);
            return;
        }
        if(num == 10) return;
        if(target < num || k == temp.size()) return;
        temp.push_back(num);
        func(num+1, target-num, k);
        temp.pop_back();
        func(num+1, target, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        func(1, n, k);
        return ans;
    }
};
