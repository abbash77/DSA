class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int left=0;
        long long sum=0;
        int right=2*k;
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(-1);
        }
        if(2*k+1>nums.size()){
            vector<int> ans1(nums.size(),-1);
            return ans1;
        }
        for(int i=0;i<2*k+1;i++){
            sum+=nums[i];
        }
        for(int i=k;i<nums.size()-k;i++){
            if(i==k){
                ans.push_back(sum/(2*k+1));
            }
            else{
                sum-=nums[left];
                left++;
                right++;
                sum+=nums[right];
                ans.push_back(sum/(2*k+1));
            }
            
        }
        for(int i=0;i<k;i++){
            ans.push_back(-1);
        }
        return ans;
    }
};