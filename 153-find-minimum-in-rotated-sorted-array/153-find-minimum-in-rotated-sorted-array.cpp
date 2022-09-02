class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=(s+e)/2;
        while(s<e){
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=(e+s)/2;
            if(e==s&&nums[s]>nums[0]){
                s=0;
                break;
            }
        }
         return nums[s];
    }
   
};