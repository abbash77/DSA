class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n);
        for(int i=0;i<n;i++){
            dist[i]=INT_MAX;
        }
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto val=q.front();
            int stop=val.first;
            int node=val.second.first;
            int distt=val.second.second;
            q.pop();
            if(stop>k){
                continue;
            }
            for(auto neighbour:adj[node]){
                if(distt+neighbour.second<dist[neighbour.first]&&stop<=k){
                    dist[neighbour.first]=distt+neighbour.second;
                    q.push({stop+1,{neighbour.first,distt+neighbour.second}});
                }
            }
            
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst]; 
    }
};