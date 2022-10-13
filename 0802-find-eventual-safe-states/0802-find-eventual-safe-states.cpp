class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int node,vector<bool> &visited,vector<bool> &dfsvisited,vector<bool>& presentcycle){
        visited[node]=true;
        dfsvisited[node]=true;
        for(auto i:graph[node]){
            if(!visited[i]){
                bool iscycle=dfs(graph,i,visited,dfsvisited,presentcycle);
                if(iscycle){
                    presentcycle[node]=true;
                    return true;
                }
                
            }
            else if(dfsvisited[i]){
                    presentcycle[node]=true;
                    return true;
                }
            
        }
        dfsvisited[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(),false);
        vector<bool> dfsvisited(graph.size(),false);
        vector<bool> presentcycle(graph.size(),false);
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                dfs(graph,i,visited,dfsvisited,presentcycle);
            }
            
        }
        for(int i=0;i<graph.size();i++){
            if(presentcycle[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};