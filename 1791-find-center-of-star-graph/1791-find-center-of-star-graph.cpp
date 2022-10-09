class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int a;
        for(auto i:adj){
            if(i.second.size()==edges.size()){
                a= i.first;
            }
        }
        return a;
    }
};