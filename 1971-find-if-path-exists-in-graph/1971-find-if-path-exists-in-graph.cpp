class Solution {
public:
    void bfs(unordered_map<int,set<int>>& adjList,unordered_map<int,bool> &visited,bool& ans,int node,int d){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adjList[front]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
            if(i==d){
                ans=true;
            }
        }
    }
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         unordered_map<int,set<int>> adjList;
    bool ans=false;
        if (source == destination) return (true);
    unordered_map<int,bool> visited;
        for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
        int i=source;
        if(!visited[i]){
            bfs(adjList,visited,ans,i,destination);
        }
    return ans;
    }
};