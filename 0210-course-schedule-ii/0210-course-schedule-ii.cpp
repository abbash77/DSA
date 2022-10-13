class Solution {
public:
    
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int> indegree(V,0);
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto i:adj[front]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()!=V){
            ans.clear();
            return ans;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};