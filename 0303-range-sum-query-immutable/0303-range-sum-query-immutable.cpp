class NumArray {
public:
    vector<int> v;
    vector<int> suffix;
    NumArray(vector<int>& nums) {
        v=nums;
        suffix.resize(nums.size(),0);
        suffix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            suffix[i]=suffix[i-1]+nums[i];
        }
    }
    // -2 -2 1    1- 
    int sumRange(int left, int right) {
        if(left>=1){
            return suffix[right]-suffix[left-1];
        }
        return suffix[right];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */