class Solution {
public:
       int getLengthOfLCS(string & str1, string & str2) {
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
  return dp[n1][n2];
}
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        int lcs=getLengthOfLCS(word1,word2);
        return n1+n2-2*lcs;
    }
};