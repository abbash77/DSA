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
         return s;
    }
    int binSearch(vector<int>& nums, int target,int s,int e){
        int mid=(s+e)/2;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return -1;
    }
   
    int search(vector<int>& nums, int target) {
        int pivot=findMin(nums);
        int a=binSearch(nums,target,0,pivot-1);
        int b=binSearch(nums,target,pivot,nums.size()-1);
        if(a==-1&&b==-1){
            return -1;
        }
        else if(b==-1){
            return a;
        }
        else{
            return b;
        }
        
    }
};