class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=(s+e)/2;
        int ans=-1;
        while(s<=e){
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                ans=mid;
                e=mid-1;
            }
            mid=(e+s)/2;
        }
        cout<<ans;
        if(ans==-1){
            return 0;
        }
         return ans;
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