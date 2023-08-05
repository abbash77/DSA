class Solution {
public:
    void bfs(vector<bool>& visited,vector<vector<int>>& isConnected,int node,int &cnt){
        visited[node]=true;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(int j=0;j<isConnected[front].size();j++){
                if(!visited[j]&&isConnected[front][j]==1){
                    q.push(j);
                    visited[j]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                bfs(visited,isConnected,i,cnt);
            }
        }
        return cnt;
    }
};