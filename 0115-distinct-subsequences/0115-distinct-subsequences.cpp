class Solution {
public:
    int MOD=1e9+7;
    int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        vector<int> prev(n2+1,0);
        vector<int> curr(n2+1,0);
        
        curr[0]=prev[0]=1;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]= (prev[j]+prev[j-1])%MOD;
                }
                else{
                    curr[j]= prev[j];
                }
            }
            prev=curr;
        }
        return prev[n2];
    }
};