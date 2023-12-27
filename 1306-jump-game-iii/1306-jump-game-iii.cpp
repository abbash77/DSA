class Solution {
public:
    bool recur(int i,vector<int>& arr,vector<int> &dp){
        if(i>=arr.size()||i<0){
            return false;
        }
        if(arr[i]==-1){
            return false;
        }
        if(arr[i]==0){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int val=arr[i];
        arr[i]=-1;
        bool left=recur(i-val,arr,dp);
        bool right=recur(i+val,arr,dp);
        arr[i]=val;
        return dp[i]= left||right;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(),-1);
        return recur(start,arr,dp);
    }
};