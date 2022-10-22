class Solution {
public:
    vector<vector<int>> finalans;
   
    void helper(vector<int>& candidates, int target,vector<int> &ans,int i,int sum){
        if(i>=candidates.size()){
            return;
        }
        helper(candidates,target,ans,i+1,sum);
        if(sum+candidates[i]>target){
            return;
        }
        sum+=candidates[i];
        ans.push_back(candidates[i]);
        if(sum==target){
            finalans.push_back(ans);
        }
        helper(candidates,target,ans,i,sum);
        ans.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         int sum=0;
        vector<int> ans;
        helper(candidates,target,ans,0,sum);
        return finalans;
    }
};