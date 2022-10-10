class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<times.size();i++){
        int u=times[i][0];
        int v=times[i][1];
        int w=times[i][2];
        adj[u].push_back({v,w});
    }
    //dist node
    set<pair<int,int>> s;
    vector<int> dist(n+1);
    for(int i=0;i<=n;i++){
        dist[i]=INT_MAX;
    }
    dist[k]=0;
    s.insert({0,k});
    while(!s.empty()){
        auto top=*(s.begin());
        int nodeDistance=top.first;
        int topNode=top.second;
        s.erase(s.begin());
        for(auto neighbour:adj[topNode]){
            if(nodeDistance+neighbour.second<dist[neighbour.first]){
                auto record=s.find(make_pair(dist[neighbour.first],neighbour.first));
                if(record!=s.end()){
                    s.erase(record);
                }
                dist[neighbour.first]=nodeDistance+neighbour.second;
                s.insert({nodeDistance+neighbour.second,neighbour.first});
            }
        }
        
    }
    int z=INT_MAX;
        for(int i=1;i<dist.size();i++){
            if(dist[i]==z){
                return -1;
            }
        }
    int maxi=INT_MIN;
    for(int i=1;i<dist.size();i++){
        if(maxi<dist[i]){
            maxi=dist[i];
        }
    }    
    return maxi;
    }
};