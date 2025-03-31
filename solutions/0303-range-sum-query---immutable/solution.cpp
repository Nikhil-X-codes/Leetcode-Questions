class NumArray {
public:
    vector<int>nums;
    
    NumArray(vector<int>& nums) {
        this->nums=nums;
    }
    
    int sumRange(int left, int right) {
        
        return accumulate(nums.begin() + left,nums.begin() + right +1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
