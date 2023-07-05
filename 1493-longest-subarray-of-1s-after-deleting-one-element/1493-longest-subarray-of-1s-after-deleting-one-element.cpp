class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(-1);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ans.push_back(i);
            }
        }
        ans.push_back(nums.size());
        if(ans.size()==2){
            return nums.size()-1;
        }
        int maxi=INT_MIN;
        for(int i=1;i<ans.size()-1;i++){
            
            int z=abs(ans[i]-ans[i-1])+abs(ans[i+1]-ans[i])-2;
            maxi=max(maxi,z);
        }
        return maxi;
    }
};