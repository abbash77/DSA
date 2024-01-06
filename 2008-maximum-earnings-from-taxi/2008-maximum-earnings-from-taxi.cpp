class Solution {
public:
    long long recur(int i,vector<vector<int>>& rides,vector<int>& start,int n,vector<long long> &dp){
        if(i>=rides.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long nt=recur(i+1,rides,start,n,dp);
        int idx=lower_bound(start.begin(),start.end(),rides[i][1])-start.begin();
        long long t=rides[i][2]+rides[i][1]-rides[i][0]+recur(idx,rides,start,n,dp);
        return dp[i]= max(nt,t);
        
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<int> start;
        for(int i=0;i<rides.size();i++){
            start.push_back(rides[i][0]);
        }
        sort(start.begin(),start.end());
        sort(rides.begin(),rides.end());
        vector<long long> dp(rides.size(),-1);
        return recur(0,rides,start,n,dp);
    }
};