class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<long long,vector<long long>> adj;
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<long long> z;
        for(auto i:adj){
            z.push_back(i.second.size());
        }
        sort(z.begin(),z.end());
        long long ans=0;
        for(int i=z.size()-1;i>=0;i--){
            ans+=z[i]*n;
            n--;
        }
        return ans;
    }
};