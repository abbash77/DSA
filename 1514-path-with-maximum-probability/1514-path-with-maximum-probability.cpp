class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& vec, vector<double>& succProb, int source, int end) {
    unordered_map<int,vector<pair<int,double>>> adj;
    for(int i=0;i<vec.size();i++){
        int u=vec[i][0];
        int v=vec[i][1];
        double w=succProb[i];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    //dist node
    priority_queue<pair<double,int>> s;
    vector<double> dist(n);
    for(int i=0;i<n;i++){
        dist[i]=0.0;
    }
    dist[source]=1.0;
    s.push({1.0,source});
    while(!s.empty()){
        auto top=s.top();
        double nodeDistance=top.first;
        int topNode=top.second;
        s.pop();
        for(auto neighbour:adj[topNode]){
            
            if(nodeDistance*neighbour.second>dist[neighbour.first]){
                dist[neighbour.first]=nodeDistance*neighbour.second;
                s.push({nodeDistance*neighbour.second,neighbour.first});
            }
        }
        
    }
    return dist[end];
    }
};