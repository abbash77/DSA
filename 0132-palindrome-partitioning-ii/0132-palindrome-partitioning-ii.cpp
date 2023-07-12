class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n+1, 0);
        int b=0;
        int a=0;
        for(int i=n-1;i>=0;i--){
            int mini=1e9;
            for(int j=i;j<s.length();j++){
                if(isPalindrome(i,j,s)){
                    int ans=1+dp[j+1];
                    mini=min(mini,ans);
                }
            }
            dp[i]= mini;
        }
        return dp[0]-1;
    }
};