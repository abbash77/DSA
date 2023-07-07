class Solution {
public:
    int recur(int n1,int n2,string word1, string word2,vector<vector<int>> &dp){
        if(n1<0){
            return n2+1;
        }
        if(n2<0){
            return n1+1;
        }
        if(dp[n1][n2]!=-1){
            return dp[n1][n2];
        }
        if(word1[n1]==word2[n2]){
            return dp[n1][n2]= recur(n1-1,n2-1,word1,word2,dp);
        }
        else{
            int a=1+recur(n1-1,n2,word1,word2,dp);//delete
            int b=1+recur(n1,n2-1,word1,word2,dp);//insert
            int c=1+recur(n1-1,n2-1,word1,word2,dp);//replace
            return dp[n1][n2]= min(a,min(b,c));
        }
    }
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=n2;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }
                else{
                    int a=1+dp[i-1][j];//delete
                    int b=1+dp[i][j-1];//insert
                    int c=1+dp[i-1][j-1];//replace
                    dp[i][j]= min(a,min(b,c));
                }
            }
        }
        return dp[n1][n2];
    }
};