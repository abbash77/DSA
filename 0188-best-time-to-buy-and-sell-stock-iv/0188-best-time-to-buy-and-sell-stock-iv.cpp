class Solution {
public:
    int recur(int i,int buy,int allowed,vector<int>& prices,vector<vector<vector<int>>> &dp){
	if(allowed==0){
            return 0;
        }
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy][allowed]!=-1){
            return dp[i][buy][allowed];
        }
        if(buy&&allowed>0){
            int a=-prices[i]+recur(i+1,0,allowed,prices,dp);
            int b=recur(i+1,1,allowed,prices,dp);
            return dp[i][buy][allowed]= max(a,b);
        }
        else if(buy==0){
            int a=prices[i]+recur(i+1,1,allowed-1,prices,dp);
            int b=recur(i+1,0,allowed,prices,dp);
            return dp[i][buy][allowed]= max(a,b);
        }
        return 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        // int n=prices.size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return recur(0,1,k,prices,dp);
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int l=1;l<k+1;l++){
                    if(j&&k>0){
                        int a=-prices[i]+dp[i+1][0][l];
                        int b=dp[i+1][1][l];
                        dp[i][j][l]= max(a,b);
                    }
                    else if(j==0){
                        int a=prices[i]+dp[i+1][1][l-1];
                        int b=dp[i+1][0][l];
                        dp[i][j][l]= max(a,b);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};