class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int sum2=0;
        for(int i=0;i<nums.size();i++){
            int a=sum-sum2-nums[i];
            if(a==sum2){
                return i;
            }
            sum2+=nums[i];
        }
        return -1;
    }
};