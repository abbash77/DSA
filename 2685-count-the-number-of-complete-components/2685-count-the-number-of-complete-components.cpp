class DSU{
    public:
    int n;
    vector<int> parent;
    vector<int> size;
    ////////////////////////////as ques demands
    vector<int> edg;
    DSU(int d){
        n=d;
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        size.resize(n,1);
        edg.resize(n,0);
    }
    int findParent(int a){
        if(parent[a]==a){
            return a;
        }
        return parent[a]=findParent(parent[a]);
    }
    void unionBySize(int a,int b){
        int para=findParent(a);
        int parb=findParent(b);
        if(para==parb){
            //bcz yahan dsu se matlb nhi hai yahan seedha for loop se dikh rsaha ki ek edge hai to humin badhana hai
            //size==no of vertices
            //n(n-1)/2 total max edges formuale 
            //we just have to check that
            edg[para]++;
            return;
        }
        else if(size[para]==size[parb]){
            parent[parb]=para;
            size[para]+=size[parb];
            edg[para]++;
        }
        else if(size[para]>size[parb]){
            parent[parb]=para;
            size[para]+=size[parb];
            edg[para]++;
        }
        else{
            parent[para]=parb;
            size[parb]+=size[para];
            edg[parb]++;
        }
    }

    
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU d(n);
        for(int i=0;i<edges.size();i++){
            d.unionBySize(edges[i][0],edges[i][1]);
        }
        int count=0;
        for(int i=0;i<d.parent.size();i++){
            if(d.parent[i]==i){
                int m=d.size[i];
                int x=(m*(m-1))/2;
                if(d.edg[i]==x){
                    count++;
                }
            }
        }
        return count;
    }
};