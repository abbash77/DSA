class Solution {
public:
    vector<string> ans;
    void recur(string s,int n,int start,unordered_map<string,int> m,string st1){
        if(start==n){
            
            st1.pop_back();
            ans.push_back(st1);
            return;
            
        }
        // if(dp[start][n]!=-1){
        //     return dp[start][n];
        // }
        for(int i=start;i<n;i++){
            string st=s.substr(start,i-start+1);
            if(m.find(st)!=m.end()){
                // st1+=st+" ";
                recur(s,n,i+1,m,st1+st+" ");   
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> m;
         int n=s.length();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int i=0;i<wordDict.size();i++){
            m[wordDict[i]]++;
        }
        string st1="";
       
        recur(s,n,0,m,st1);
        return ans;
    }
};