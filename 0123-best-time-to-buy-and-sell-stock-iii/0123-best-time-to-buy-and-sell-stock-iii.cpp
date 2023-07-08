class Solution {
public:
    int recur(int i,int buy,int allowed,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy][allowed]!=-1){
            return dp[i][buy][allowed];
        }
        if(buy&&allowed>0){
            int a=-prices[i]+recur(i+1,0,allowed-1,prices,dp);
            int b=recur(i+1,1,allowed,prices,dp);
            return dp[i][buy][allowed]= max(a,b);
        }
        else if(buy==0){
            int a=prices[i]+recur(i+1,1,allowed,prices,dp);
            int b=recur(i+1,0,allowed,prices,dp);
            return dp[i][buy][allowed]= max(a,b);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        dp[n][0][0]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=0;k<3;k++){
                    if(j&&k>0){
                        int a=-prices[i]+dp[i+1][0][k-1];
                        int b=dp[i+1][1][k];
                        dp[i][j][k]= max(a,b);
                    }
                    else if(j==0){
                        int a=prices[i]+dp[i+1][1][k];
                        int b=dp[i+1][0][k];
                        dp[i][j][k]= max(a,b);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};