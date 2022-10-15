class Solution {
public:
    void dfs(unordered_map<int,vector<int>> adj, vector<bool>& visited,int t, int target,double ans,int node,double& finalans){
        visited[node]=true;
        if(adj[node].size()-1==0&&node==target&&node!=1){
            finalans=ans;
            return;
        }
        else if(adj[node].size()-1>0&&node==target&&t==0){
            finalans=ans;
            return;
        }
        else if(t==0){
            return;
        }
        double s;
        if(node==1){
             s=adj[node].size();
        }
        else{
             s=adj[node].size()-1;
        }
       
        ans=ans*(1/s);
        for(auto i:adj[node]){
            if(!visited[i]){
                dfs(adj,visited,t-1,target,ans,i,finalans);
            }
        }
        
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(edges.empty()){
            return 1.0000;
        }
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        double ans=1;
        double finalans;
        vector<bool> visited(n+1,false);
        dfs(adj,visited,t,target,ans,1,finalans);
        return finalans;
    }
};