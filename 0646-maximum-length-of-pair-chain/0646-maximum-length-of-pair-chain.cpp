class Solution {
public:
    int  recur(int i,int prev,vector<vector<int>>& pairs,vector<vector<int>> &dp){
        if(i>=pairs.size()){
            return 0;
        }
        if(dp[i][prev+1001]!=-1){
            return dp[i][prev+1001];
        }
        int notPick=recur(i+1,prev,pairs,dp);
        int pick=-1e9;
        if(pairs[i][0]>prev){
            pick=1+recur(i+1,pairs[i][1],pairs,dp);
        }
        return dp[i][prev+1001] =max(pick,notPick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        
        vector<vector<int>> dp(n+1,vector<int>(2003,-1));
        // unordered_map<int,unordered_map<int,int>> dp;
        return recur(0,-1001,pairs,dp);
    }
};