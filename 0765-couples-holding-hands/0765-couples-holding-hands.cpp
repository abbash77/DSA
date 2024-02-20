class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        vector<int> parent(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i=i+2){
            int u=findParent(row[i],parent);
            int v=findParent(row[i+1],parent);
            if(u!=v){
                parent[u]=v;
            }
        }
        int res=0;
        for(int i=0;i<n;i=i+2){
            int u=findParent(i,parent);
            int v=findParent(i+1,parent);
            if(u!=v){
                res++;
                parent[u]=v;
            }
        }
        return res;
    }
    int findParent(int u,vector<int> &parent){
        if(parent[u]==u){
            return u;
        }
        return parent[u]= findParent(parent[u],parent);
    }
};