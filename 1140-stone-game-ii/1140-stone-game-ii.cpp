class Solution {
public:
    int recur(int idx,int M,vector<int> piles,int chance,vector<vector<vector<int>>> &dp){
        if(idx==piles.size()){
            return 0;
        }
        if(dp[idx][M][chance]!=-1){
            return dp[idx][M][chance];
        }
        if(chance==1){
            int sum=0;
            int maxi=0;
            for(int i=1;i<=2*M;i++){
                int startIndex=idx+i-1;
                if(startIndex>=piles.size()){
                    break;
                }
                sum+=piles[startIndex];
                maxi=max(maxi,sum+recur(startIndex+1,max(M,i),piles,0,dp));
            }
            return dp[idx][M][chance]= maxi;
        }
        else{
            int maxi=1e9;
            for(int i=1;i<=2*M;i++){
                int startIndex=idx+i-1;
                if(startIndex>=piles.size()){
                    break;
                }
                maxi=min(maxi,recur(startIndex+1,max(M,i),piles,1,dp));
            }
            return dp[idx][M][chance]= maxi;
        }
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2*n+1,vector<int>(2,-1)));
        return recur(0,1,piles,1,dp);
    }
};