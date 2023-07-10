class Solution {
public:
    int recur(int i,int j,vector<int>& cuts,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        int mini=1e9;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=i;k<=j;k++){
            int val=cuts[j+1]-cuts[i-1]+recur(i,k-1,cuts,dp)+recur(k+1,j,cuts,dp);
            mini=min(mini,val);
        }
        return dp[i][j]= mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        for(int i=c;i>=1;i--){
            for(int j=i;j<=c;j++){
                int mini=1e9;
                for(int k=i;k<=j;k++){
                    int val=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,val);
                }
                dp[i][j]= mini;
            }
        }
        
        return dp[1][c];
    }
};