class Solution {
public:
    bool solve(int ind,int last_move,vector<int>&stones,vector<vector<int>>&dp,unordered_map<int,int>&mp){
        
        if(ind==stones.size()-1){
            return true;
        }
        if(last_move<=0){
            return false;
        }
        if(dp[ind][last_move]!=-1){
            return dp[ind][last_move];
        }
        if(mp.find(stones[ind]+last_move)!=mp.end()){
            int new_ind=mp[stones[ind]+last_move];
            if(solve(new_ind,last_move,stones,dp,mp)){
                return dp[ind][last_move]=true;
            }
        }
        if(mp.find(stones[ind]+last_move-1)!=mp.end()){
            int new_ind=mp[stones[ind]+last_move-1];
            if(solve(new_ind,last_move-1,stones,dp,mp)){
                return dp[ind][last_move]=true;
            }
        }
        if(mp.find(stones[ind]+last_move+1)!=mp.end()){
            int new_ind=mp[stones[ind]+last_move+1];
            if(solve(new_ind,last_move+1,stones,dp,mp)){
                return dp[ind][last_move]=true;
            }
        }
        return dp[ind][last_move]=false;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        
        if(stones[1]-stones[0]!=1){
            return false; 
        }
        unordered_map<int,int>mp; 
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,1,stones,dp,mp);
    }
};