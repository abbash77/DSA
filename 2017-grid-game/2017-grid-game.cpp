class Solution {
public:
    long long gridGame(vector<vector<int>>& arr) {
        
        int n = arr[0].size();
        long long pre1[n+1];
        long long pre2[n+1];
        
		//filling the prefix arrays
        pre1[0] = arr[0][0] , pre2[0] = arr[1][0];
        for(int i=1;i<n;i++)
        {
            pre1[i] = pre1[i-1] + arr[0][i];
            pre2[i] = pre2[i-1] + arr[1][i];
            // cout<<pre1[i]<<" ";
        }
        long long res = LONG_MAX;
        
        for(int i=0;i<n;i++)
        {
            long long op1 = pre1[n-1] - pre1[i];
            long long op2 = i==0 ? 0 : pre2[i-1];
            res = min(res,max(op1,op2));
        }
        
        return res;
    }
};