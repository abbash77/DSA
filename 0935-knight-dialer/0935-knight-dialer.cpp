class Solution {
public:
    int mod=1e9+7;
    int help(int i,int n,vector<vector<int>>&v,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(dp[n][i]!=-1)
        {
            return dp[n][i];
        }
        int ans=0;
        
        for(int j=0;j<v[i].size();j++)
        {
            ans =(ans + help(v[i][j],n-1,v,dp))%mod;
        }
          
        
        return dp[n][i]=ans;
    }
    int knightDialer(int n) {
        vector<vector<int>>v={{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
        vector<vector<int>>dp(n+1,vector<int>(10,-1));
        int ans=0;
        
        for(int i=0;i<10;i++)
        {
            ans=(ans+help(i,n-1,v,dp))%mod;
        }
        
        return ans;
    }
};