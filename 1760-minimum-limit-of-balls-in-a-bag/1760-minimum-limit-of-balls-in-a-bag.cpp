class Solution {
public:
    int check(int mid , int maxOp , vector<int> nums){
        int currOps = 0;
        for(auto a : nums){
            if(a<=mid) break;
            if(a%mid == 0)
                currOps+=((a/mid)-1);
            else
                currOps+=(a/mid);
        }
        return currOps > maxOp ? 0 : 1 ;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.rbegin() , nums.rend()); // decending order
        int s = 1 ; 
        int e = nums[0]; // high is the maximum value in array
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(check(mid , maxOperations , nums)) {
                ans = mid;
                e=mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};