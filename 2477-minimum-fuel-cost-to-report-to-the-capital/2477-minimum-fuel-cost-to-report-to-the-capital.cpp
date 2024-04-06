class Solution {
public:
    long long ans=0;
    int dfs(int node,int par,unordered_map<int,vector<int>> &adj,int seats){
        int val=1;
        for(auto neighbour:adj[node]){
            if(neighbour!=par){
                val+=dfs(neighbour,node,adj,seats);
            }
        }
        if(node!=0){
            ans+=(val-1)/seats+1;//ceil
        }
        return val;
        
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        dfs(0,-1,adj,seats);
        return ans;
    }
};