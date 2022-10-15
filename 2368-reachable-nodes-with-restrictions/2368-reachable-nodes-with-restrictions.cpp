class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj,int &cnt,vector<bool>& visited,int node){
        visited[node]=true;
        cnt++;
        for(auto i:adj[node]){
            
            if(!visited[i]){
                dfs(adj,cnt,visited,i);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        vector<bool> visited(n,false);
        for (auto a : restricted)
        {
            visited[a] = true;
        }
        
        dfs(adj,cnt,visited,0);
        return cnt;
    }
};