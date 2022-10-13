class Solution {
public:
     bool checkCycle(vector<int> adj[], int i, vector<int> &vis, vector<int> &dfsvis){
        vis[i] = 1;
        dfsvis[i] = 1;
        for(int u : adj[i]){
            if(!vis[u]){
                if(checkCycle(adj, u, vis, dfsvis)) return true;
            }
            else if(dfsvis[u]) return true;
        }
        dfsvis[i] = 0;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& pr) {
        // Build graph
        vector<int> adj[V];
        for(int i = 0; i<pr.size(); ++i){
            int u = pr[i][0];
            int v = pr[i][1];
            adj[v].push_back(u);
        }
        // check whether graph is DAG or not
        vector<int> visited(V, 0);
        vector<int> dfsvis(V, 0);
        for(int i = 0; i<V; ++i){
            if(!visited[i]){
                if(checkCycle(adj, i, visited, dfsvis)) return false;
            }
        }
        return true;
    }
};