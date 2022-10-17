class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<int> inorder(n,0);
        for(auto j:adj){
            for(auto i:j.second){
                inorder[i]++;
            }
        }
        vector<int> ans;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};