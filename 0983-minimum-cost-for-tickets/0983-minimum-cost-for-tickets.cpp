class Solution {
public:
    int recur(vector<int>& days, vector<int>& costs,int i,int valid,vector<vector<int>> &dp){
         if(i >= days.size())
            return 0;
         if(dp[i][valid] != -1) return dp[i][valid];
        if(days[i] <= valid)
            return dp[i][valid] = recur(days, costs, i+1, valid,dp);
        else {
            int ch1 = costs[0] + recur(days, costs, i+1, days[i],dp);
            int ch2 = costs[1] + recur(days, costs, i+1, days[i]+6,dp);
            int ch3 = costs[2] + recur(days, costs, i+1, days[i]+29,dp);
            return dp[i][valid] = min(ch1, min(ch2, ch3));
        }
            
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size()+1,vector<int>(400,-1));
       return recur(days, costs, 0, 0,dp);
    }
};