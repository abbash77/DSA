class Solution {
public:
    int findParent(int u,vector<int>& parent){
        if(parent[u]==u){
            return u;
        }
        else{
           return parent[u]=findParent(parent[u],parent); 
        }
        
    }
    void unioni(int u,int v,vector<int>& parent){
        int p1=findParent(u,parent);
        int p2=findParent(v,parent);
        if(p1==p2){
            return;
        }
        else if(p1!=p2){
            parent[p2]=p1;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       vector<int> parent(edges.size()+1);
        for(int i=0;i<edges.size()+1;i++){
            parent[i]=i;
        }
        vector<int> ans(2,0);
        for(int i=0;i<edges.size();i++){
            if(findParent(edges[i][0],parent)==findParent(edges[i][1],parent)){
                ans[0]=edges[i][0];
                ans[1]=edges[i][1];
                break;
            }
            else{
                unioni(edges[i][0],edges[i][1],parent);
            }
        }
        return ans;
    }
};
// int find_parent(int a){
//         if(parents[a] == a){
//             return a;
//         } else {
//             return parents[a] = find_parent(parents[a]);    //Finding parents using path compression
//         }
//     }
//     void do_union(int node1 , int node2){   
//         node1 = find_parent(node1);
//         node2 = find_parent(node2);
//         if(node1 == node2){     // If they have same parents, do nothing
//             return;
//         } else {                //Else, connect node1 to node2 by assigning the parent of node1 to node2
//             parents[node2] = node1;
//             return;
//         }
//     }
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         parents = vector<int>(1001);
//         for(int i = 0 ; i < 1001 ; ++i){    //Self initializing the parents, because every node is disconnected at first.
//             parents[i] = i;
//         }
//         vector<int> answer(2 , 0);
//         for(int i = 0 ; i < edges.size() ; ++i){
//             if(find_parent(edges[i][0]) == find_parent(edges[i][1])){   //If parents of these nodes are same, means they already visited/connected, hence contributing in cycle.
//                 answer[0] = edges[i][0];
//                 answer[1] = edges[i][1];
//                 break;
//             } else {
//                 do_union(edges[i][0] , edges[i][1]);
//             }
//         }
//         return answer;