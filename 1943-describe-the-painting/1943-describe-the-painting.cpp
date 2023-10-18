class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long,long long> m;
        vector<vector<long long>> v;
        for(int i=0;i<segments.size();i++){
            m[segments[i][0]]+=segments[i][2];
            m[segments[i][1]]-=segments[i][2];
        }
        long long int j=0,k=0;
        for(auto x:m)
        {
            long long int prev=j;
            j+=x.second;
            if(prev>0)
                v.push_back({k,x.first,prev});
            k=x.first;
        }
        return v;
    }
};