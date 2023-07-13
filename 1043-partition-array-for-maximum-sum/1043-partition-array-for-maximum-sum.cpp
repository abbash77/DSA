class Solution {
public:
    int recur(int i,vector<int>& arr,int k,vector<int> &dp){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int sum=INT_MIN;
        int maxi=-1e9;
        for(int j=i;j<i+k&&j<arr.size();j++){
            sum=max(sum,arr[j]);
            int ans=sum*(j-i+1)+recur(j+1,arr,k,dp);
            maxi=max(maxi,ans);
        }
        return dp[i]= maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int sum=INT_MIN;
            int maxi=-1e9;
            for(int j=i;j<i+k&&j<arr.size();j++){
                sum=max(sum,arr[j]);
                int ans=sum*(j-i+1)+dp[j+1];
                maxi=max(maxi,ans);
            }
            dp[i]= maxi;
        }
        return  dp[0];
    }
};