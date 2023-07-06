class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) {
        int n1=str1.length();
  int n2=str2.length();
  vector<int> prev(n2+1,0);
  for(int i=1;i<n1+1;i++){
    vector<int> curr(n2+1,0);
    for(int j=1;j<n2+1;j++){
      if(str1[i-1]==str2[j-1]){
        curr[j]= 1+prev[j-1];
      }
      else{
        curr[j]= max(prev[j],curr[j-1]);
      }
    }
    prev=curr;
  }
  return prev[n2];
    }
};