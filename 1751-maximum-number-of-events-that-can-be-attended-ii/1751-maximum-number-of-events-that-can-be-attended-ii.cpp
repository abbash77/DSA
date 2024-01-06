class Solution {
public:
    int f( int i , vector<vector<int>>&events ,vector<int>&start  , int k ,vector<vector<int>>&dp)
    {
        int n = start.size();
        if(i>=n)return 0;
        if(k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int index = upper_bound(start.begin() , start.end() , events[i][1]) -start.begin();
        int take  = events[i][2]+f(index  ,events, start  , k-1 , dp);
        int nottake = f(i+1  ,events, start  , k , dp);
        return  dp[i][k]=max(take, nottake);
    }
    int maxValue(vector<vector<int>>& events, int k) 
    {
        sort(events.begin() , events.end());
        vector<int>start ;
        int n = events.size();
        vector<vector<int>> dp(n+1 , vector<int>(k+1 , -1));
        for(int i =0 ; i<events.size() ;i++) start.push_back(events[i][0]);
        return f(0 , events , start , k, dp);
    }
};