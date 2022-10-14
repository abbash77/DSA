class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int& ans){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=1){
            return ;
        }
        grid[i][j]=0;
        ans+=1;
        dfs(grid,i+1,j,ans);
        dfs(grid,i,j+1,ans);
        dfs(grid,i-1,j,ans);
        dfs(grid,i,j-1,ans);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=INT_MIN;
        int ans=0;
        bool flag=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    flag=1;
                    dfs(grid,i,j,ans);
                    if(ans>maxi){
                        maxi=ans;
                    }
                    ans=0;
                }
            }
        }
        if(flag==0){
            return 0;
        }
        return maxi;
    }
};