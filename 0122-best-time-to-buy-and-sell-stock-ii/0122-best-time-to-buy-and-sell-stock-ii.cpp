class Solution {
public:
    int recur(int i,int buy,vector<int>& prices,vector<vector<int>> &dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy){
            int a=-prices[i]+recur(i+1,0,prices,dp);
            int b=recur(i+1,1,prices,dp);
            return dp[i][buy]= max(a,b);
        }
        else{
            int a=prices[i]+recur(i+1,1,prices,dp);
            int b=recur(i+1,0,prices,dp);
            return dp[i][buy]= max(a,b);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> ahead(2,0);
        vector<int> curr(2,0);
        ahead[0]=ahead[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    int a=-prices[i]+ahead[0];
                    int b=ahead[1];
                    curr[j]= max(a,b);
                }
                else{
                    int a=prices[i]+ahead[1];
                    int b=ahead[0];
                    curr[j]= max(a,b);
                }
            }
            ahead=curr;
        }
        return curr[1];
    }
};