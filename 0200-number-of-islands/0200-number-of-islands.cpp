class Solution {
public:
    void numsrecur(int i,int j,int n,int m,vector<vector<char>>& grid){
        if(i>=n||i<0||j>=m||j<0||grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        numsrecur(i+1,j,n,m,grid);
        numsrecur(i,j+1,n,m,grid);
        numsrecur(i-1,j,n,m,grid);
        numsrecur(i,j-1,n,m,grid);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    numsrecur(i,j,n,m,grid);
                }
            }
        }
        return ans;
    }
};