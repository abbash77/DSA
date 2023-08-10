class DisjointSet{
    vector<int> rank, parent,size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
	size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
	    size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
	
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DisjointSet ds(n);
        vector<pair<int,pair<int,int>> > adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj.push_back({d,{i,j}});
            }
        }
        sort(adj.begin(), adj.end());
        int ans=0;
        for(int i=0;i<adj.size();i++){
            int w=adj[i].first;
            int u=adj[i].second.first;
            int v=adj[i].second.second;
            if(ds.findUPar(u)!=ds.findUPar(v)){
                ans+=w;
                ds.unionBySize(u,v);
            }
        }
        return ans;
    }
};