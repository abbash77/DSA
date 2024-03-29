class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]<nums[n-1])return nums[0];
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else if(nums[mid]<nums[l]){
                r=mid;
                l++;
            }
            else{
                r--;
            }
        }
        return nums[l];
    }
};