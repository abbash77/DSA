class Solution {
public:
    int recur(int i,int buy,int cool,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i==prices.size()){
            return 0;
        }
       if(dp[i][buy][cool]!=-1){
           return dp[i][buy][cool];
       }
        if(cool==0){
            return recur(i+1,1,1,prices,dp);
        }
        else if(buy){
            int a=-prices[i]+recur(i+1,0,1,prices,dp);
            int b=recur(i+1,1,1,prices,dp);
            return dp[i][buy][cool]= max(a,b);
        }
        else{
            int a=prices[i]+recur(i+1,1,0,prices,dp);
            int b=recur(i+1,0,1,prices,dp);
            return dp[i][buy][cool]= max(a,b);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(2,0)));
        // for(int buy=0;buy<2;buy++){
        //     for(int cool=0;cool<2;cool++){
        //         dp[0][buy][cool]=0;
        //     }
        // }
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int cool=0;cool<2;cool++){
                    if(cool==0){
                        dp[i][buy][cool]= dp[i+1][1][1];
                    }
                    else if(buy){
                        int a=-prices[i]+dp[i+1][0][1];
                        int b=dp[i+1][1][1];
                        dp[i][buy][cool]= max(a,b);
                    }
                    else{
                        int a=prices[i]+dp[i+1][1][0];
                        int b=dp[i+1][0][1];
                        dp[i][buy][cool]= max(a,b);
                    }
                }
            }
        }
        
        return dp[0][1][1];
    }
};