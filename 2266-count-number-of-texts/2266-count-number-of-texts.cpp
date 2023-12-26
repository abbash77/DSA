class Solution {
public:
    int MOD=1e9+7; 
    int recur(int i,string& pressedKeys,unordered_map<char,int> &m,vector<int> &dp){
        if(i==pressedKeys.size()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int val=m[pressedKeys[i]];
        int ans=0;
        for(int j=i;j<pressedKeys.size()&&j<i+val;j++){
            if(pressedKeys[i]==pressedKeys[j]){
                ans=ans%MOD+recur(j+1,pressedKeys,m,dp)%MOD;
            }
            else{
                break;
            }
            
        }
        return dp[i]= ans%MOD;
        
    }
    int countTexts(string pressedKeys) {
        unordered_map<char,int> m;
        m['2']=3;
        m['3']=3;
        m['4']=3;
        m['5']=3;
        m['6']=3;
        m['7']=4;
        m['8']=3;
        m['9']=4;
        vector<int> dp(pressedKeys.size(),-1);
        return recur(0,pressedKeys,m,dp)%MOD;
    }
};