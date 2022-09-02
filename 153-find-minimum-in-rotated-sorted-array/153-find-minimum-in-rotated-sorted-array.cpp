class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int s=0;
        int e=nums.size()-1;
        int z=e;
        int mid=(s+e)/2;
        while(s<e){
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=(s+e)/2;
        }
        if(s==z&&nums[s]>nums[s-1]){
            return nums[0];
        }
        return nums[s];
    }
};