class Solution {
public:
     int maxii=0;
    int maxij=0;
    void fun(vector<vector<int>>& land,vector<vector<int>> & visited,int i,int j){
        if(i>=land.size()|| i<0||j>=land[0].size()||j<0||visited[i][j]==1||land[i][j]==0){
            return;
        }
       
        if(i>=maxii){
            maxii=i;
        }
        if(j>=maxij){
            maxij=j;
        }
       
        visited[i][j]=1;
        fun(land,visited,i-1,j);
        fun(land,visited,i,j-1);
        fun(land,visited,i,j+1);
        fun(land,visited,i+1,j);
       
       
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row=land.size();
        int col=land[0].size();
        vector<vector<int>> visited(row,vector<int>(col,0));
        vector<vector<int>> coor;
        vector<int> ans;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(land[i][j]==1){
                    if(!visited[i][j]){
                        ans.push_back(i);
                        ans.push_back(j);
                        fun(land,visited,i,j);
                        cout<<maxii<<" "<<maxij<<endl;
                        ans.push_back(maxii);
                        ans.push_back(maxij);    
                        coor.push_back(ans);
                        maxii=0;
                        maxij=0;
                        ans.clear();
                    }
                }
            }
        }
        return coor;
    }
};