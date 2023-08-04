class Solution {
public:
    bool recur(string s,int n,int start,unordered_map<string,int> m,vector<vector<int>>& dp){
        if(start==n){
            return true;
        }
        if(dp[start][n]!=-1){
            return dp[start][n];
        }
        for(int i=start;i<n;i++){
            string st=s.substr(start,i-start+1);
            if(m.find(st)!=m.end()){
                if(recur(s,n,i+1,m,dp)){
                    return dp[start][n]= true;
                }
            }
        }
        return dp[start][n]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> m;
         int n=s.length();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int i=0;i<wordDict.size();i++){
            m[wordDict[i]]++;
        }
       
        return recur(s,n,0,m,dp);
    }
};