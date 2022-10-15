class Solution {
public:
    void helper(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=0){
            return;
        }
        grid[i][j]=2;
        helper(grid,i-1,j);
        helper(grid,i,j-1);
        helper(grid,i+1,j);
        helper(grid,i,j+1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            helper(grid,i,0);
            helper(grid,i,m-1);
        }
           
        for(int j=0; j<m; j++){
            helper(grid,0,j);
            helper(grid,n-1,j);
        }
            
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    helper(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};