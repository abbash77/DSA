class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int> v1,int node,vector<bool> visited,int dest){
        visited[node]=true;
        v1.push_back(node);
        if(dest==node){
            ans.push_back(v1);
        }
        for(auto i:graph[node]){
            dfs(graph,ans,v1,i,visited,dest);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src=0;
        int dest=graph.size()-1;
        vector<vector<int>> ans;
        vector<int> v1;
        vector<bool> visited(graph.size(),false); 
        dfs(graph,ans,v1,src,visited,dest);
        return ans;
    }
};