class Solution {
public:
    int recur(int i,int& d, vector<int>& arr,vector<int>& dp){
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans1=INT_MIN;
        for(int j=i+1;j<=i+d&&j<arr.size();j++){
            if(arr[i]>arr[j]){
                ans1=max(ans1,1+recur(j,d,arr,dp));
            }
            else{
                break;
            }
        }
        for(int j=i-1;j>=i-d&&j>=0;j--){
            if(arr[i]>arr[j]){
                ans1=max(ans1,1+recur(j,d,arr,dp));
            }
            else{
                break;
            }
        }
        if(ans1==INT_MIN){
            return dp[i]=0;
        }
        else{
            return dp[i]= ans1;
        }
        
    }
    int maxJumps(vector<int>& arr, int d) {
        int maxi=INT_MIN;
        vector<int> dp(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            int ans=1+recur(i,d,arr,dp);
            
            maxi=max(maxi,ans);

            
        }
        return maxi;
    }
};