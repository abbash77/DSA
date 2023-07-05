class Solution {
public:
    int change(int T, vector<int>& arr) {
        int n=arr.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,0));
        vector<long> prev(T+1,0);
    
    
    //Initializing base condition
    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            prev[i]=1;
        // Else condition is automatically fulfilled,
        // as prev array is initialized to zero
    }
    
    for(int ind=1; ind<n;ind++){
        vector<long> cur(T+1,0);
        for(int target=0;target<=T;target++){
            long notTaken = prev[target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = cur[target-arr[ind]];
                
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    
    return prev[T];
    }
};