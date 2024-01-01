class Solution {
public:
    int arraySign(vector<int>& nums) {
        int isZero=0;
        int cntNeg=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                isZero=1;
            }
            if(nums[i]<0){
                cntNeg++;
            }
        }
        if(isZero==1){
            return 0;
        }
        if(cntNeg%2!=0){
            return -1;
        }
        return 1;
        
    }
};