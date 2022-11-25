class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int a=0;
        int b=1;
        if(nums.size()==1){
            return nums[0];
        }
        
        for(int i=0;i<=nums.size()/2;i++){
            if(nums[a]==nums[b]){
                a+=2;;
                b+=2;
            }
            else{
                return nums[a];
            }
        }
        return -1;
    }
};