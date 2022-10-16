class Solution {
public:
    void helper(vector<vector<int>>& grid2, int i, int j,bool &imp,vector<vector<int>>& grid1){
        if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size() || grid2[i][j]!=1){
            return;
        }
        if(grid1[i][j]==0){
            imp=true;
        }
        grid2[i][j]=0;
        helper(grid2,i-1,j,imp,grid1);
        helper(grid2,i,j-1,imp,grid1);
        helper(grid2,i+1,j,imp,grid1);
        helper(grid2,i,j+1,imp,grid1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool imp=false;
                if(grid2[i][j]==1){
                    helper(grid2,i,j,imp,grid1);
                    if(!imp){
                        ans++;
                    }
                }
                
            }
        }
        return ans;
    }
};