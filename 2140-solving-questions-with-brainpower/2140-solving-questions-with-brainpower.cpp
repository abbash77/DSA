class Solution {
public:
    long long recur(int i,vector<vector<int>>& questions,vector<long long> &dp){
        if(i>=questions.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long notPick=recur(i+1,questions,dp);
        long long pick=questions[i][0]+recur(i+1+questions[i][1],questions,dp);
        return dp[i]= max(notPick,pick);    
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return recur(0,questions,dp);
    }
    
};