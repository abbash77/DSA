class DSU{
    public:
    vector<int> rank;
    vector<int> parent;
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findPar(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findPar(parent[u]);
    }
    void unionSet(int u,int v){
        u=findPar(u);
        v=findPar(v);
        if(u==v){
            return;
        }
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
};
class Solution {
public:
    bool isSimilar(string a,string b){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                cnt++;
            }
        }
        if(cnt>2){
            return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DSU d1(n);
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                if(isSimilar(strs[i],strs[j])){
                    d1.unionSet(i,j);      
                }
            }
        }
        int ans=0;
        for(int i=0;i<d1.parent.size();i++){
            if(d1.parent[i]==i){
                ans++;
            }
            
        }
        return ans;
    }
};