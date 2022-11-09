class Solution {
public:
     vector<vector<int>> finalans;
   
    void helper(vector<int>& candidates, int target,vector<int> &ans,int index,int n){
        if(target==0){
            finalans.push_back(ans);
            return;
        }
        for(int i=index;i<n;i++){
            if(i>index&&candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            ans.push_back(candidates[i]);
            helper(candidates,target-candidates[i],ans,i+1,n);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,ans,0,n);
        return finalans;
    }
};