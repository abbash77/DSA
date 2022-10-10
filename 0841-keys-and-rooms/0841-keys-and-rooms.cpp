class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<rooms.size();i++){
            for(auto j:rooms[i]){
                adj[i].push_back(j);
            }
        }
        vector<bool> visited(rooms.size());
        visited[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto neighbour:adj[front]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};