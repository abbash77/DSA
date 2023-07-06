class Solution {
public:
      string getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
      int n1=str1.length();
      int n2=str2.length();
    vector<vector<int>> dp( n1+1,vector<int>(n2+1,0));
      //shift index by 1 to write tabulation
      for(int i=1;i<n1+1;i++){
        for(int j=1;j<n2+1;j++){
          if(str1[i-1]==str2[j-1]){
            dp[i][j]= 1+dp[i-1][j-1];
          }
          else{
            dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
          }
        }
      }
        int i=n1;
        int j=n2;
          string ans="";
      while(i>0&&j>0){
        if(str1[i-1]==str2[j-1]){
            ans+=str1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            ans+=str1[i-1];
            i--;
        }
          else{
            ans+=str2[j-1];
            j--;
          }
      }
          if(i!=0){
              for(int k=i-1;k>=0;k--){
                  ans+=str1[k];
              }
          }
          if(j!=0){
              for(int k=j-1;k>=0;k--){
                  ans+=str2[k];
              }
              
          }
          reverse(ans.begin(),ans.end());
          return ans;
          
}
    string shortestCommonSupersequence(string str1, string str2) {
        return getLengthOfLCS(str1,str2);
    }
};