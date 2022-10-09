class Solution {
public:
    void bfs( unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,int node,int &cnt){
        queue<int> q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto i:adj[top]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                    cnt++;
                }
            }
        }
        
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<long long> dummy;
        unordered_map<int,bool> visited;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int cnt=1;
                bfs(visited,adj,i,cnt);
                dummy.push_back(cnt);
            }
        }
        // long long ans=0;
        // for(int i=0;i<dummy.size();i++){
        //     for(int j=i+1;j<dummy.size();j++){
        //         ans+=dummy[i]*dummy[j];
        //     }
        // }
        // return ans;
        if(dummy.size()==1) return 0;
       long long ans=0;
        long long sumsquare=0;
        long long sum=0;
        for(auto i:dummy){
            sum+=i;
            sumsquare+=i*i;
        }
        sum=sum*sum;
        sum=sum-sumsquare;
        return sum/2;
    }
};