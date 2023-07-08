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
        vector<vector<int>> after(2,vector<int>(2,0));
        vector<vector<int>> curr(2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int cool=0;cool<2;cool++){
                    if(cool==0){
                        curr[buy][cool]= after[1][1];
                    }
                    else if(buy){
                        int a=-prices[i]+after[0][1];
                        int b=after[1][1];
                        curr[buy][cool]= max(a,b);
                    }
                    else{
                        int a=prices[i]+after[1][0];
                        int b=after[0][1];
                        curr[buy][cool]= max(a,b);
                    }
                }
            }
            after=curr;
        }
        
        return curr[1][1];
    }
};