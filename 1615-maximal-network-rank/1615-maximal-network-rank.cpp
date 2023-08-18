class Solution {
public:
    bool isConnected(vector<int> a,int val){
        for(int i=0;i<a.size();i++){
            if(a[i]==val){
                return true;
            }
        }
        return false;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> connected;
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int a=adj[i].size();
                int b=adj[j].size();
                int ans=a+b;
                if(isConnected(adj[i],j)){
                    ans--;
                }
                maxi=max(maxi,ans);
            }
        }
        return maxi;
    }
};