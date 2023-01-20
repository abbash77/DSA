class Solution {
public:
    void helper(vector<int> &ans, set<vector<int>> &finalans,int index,vector<int>& nums,int prev){
        if(ans.size()>=2){
            finalans.insert(ans);
        }
        if(index>=nums.size()){
            
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(nums[i]>=prev){
                ans.push_back(nums[i]);
                helper(ans,finalans,i+1,nums,nums[i]);
                ans.pop_back();
            }
            
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> finalans;
        vector<vector<int>> answer;
        vector<int> ans;
        int index=0;
        int prev=-110;
        helper(ans,finalans,index,nums,prev);
        for(auto m:finalans){
            answer.push_back(m);
        }
        return answer;
    }
};