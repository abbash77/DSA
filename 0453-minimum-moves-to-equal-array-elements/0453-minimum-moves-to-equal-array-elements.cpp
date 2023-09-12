class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            sum+=nums[i];
        }
        return sum-n*mini;
    }
};