class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int> v1,int node,int dest){
        v1.push_back(node);
        if(dest==node){
            ans.push_back(v1);
        }
        for(auto i:graph[node]){
            dfs(graph,ans,v1,i,dest);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src=0;
        int dest=graph.size()-1;
        vector<vector<int>> ans;
        vector<int> v1;
        dfs(graph,ans,v1,src,dest);
        return ans;
    }
};