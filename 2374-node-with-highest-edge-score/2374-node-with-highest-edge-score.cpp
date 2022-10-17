class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int,int> mp;
        for(int i=0;i<edges.size();i++){
            mp[i]=edges[i];
        }
        vector<long> indegree(edges.size(),0);
        for(auto i:mp){
            indegree[i.second]+=i.first;
        }
        long maxi=INT_MIN;
        long maxiIndex;
        for(long i=0;i<indegree.size();i++){
            if(indegree[i]>maxi){
                maxi=indegree[i];
                maxiIndex=i;
            }
        }
        return maxiIndex;
        
        
        
    }
};