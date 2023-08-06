class Solution {
public:
    bool check(int start,vector<vector<int>>& graph,vector<int> &color){
        queue<int> q;
        
        color[start]=0;
        q.push(start);
        while(!q.empty()){
            int val=q.front();
            q.pop();
            for(auto neigh:graph[val]){
                if(color[neigh]==-1){
                    color[neigh]=!color[val];
                    q.push(neigh);
                }
                else if(color[neigh]==color[val]){
                    return false;
                }
                
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(check(i,graph,color)==false){
                    return false;
                }
            }
            
        }
        return true;
    }
};