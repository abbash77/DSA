class DisjointSet {
    
public:
    vector<int> rank, parent,size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
	size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
	    size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
	
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
void dfs(int node,unordered_map<int,vector<int>> adj,vector<int>& visited){
    visited[node]=1;
    for(auto neigh:adj[node]){
        if(!visited[neigh]){
            dfs(neigh,adj,visited);
        }
    }
}
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cnt=0;
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            // adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(auto i:adj){
            for(auto j:i.second){
                if(ds.findUPar(i.first)!=ds.findUPar(j)){
                    ds.unionBySize(i.first,j);
                }
                else{
                    cnt++;
                }
            }
        }
        // cout<<cnt<<endl;
        int total=0;
        for(int i = 0; i < n; i++){
            total += ds.parent[i] == i? 1 : 0;
        }
        // cout<<a;
        if(cnt>=total-1){
            return total-1;
                
        }
        return -1;
    }
};