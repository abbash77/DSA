class Solution {
public:
    int nobs=1;
    int ans=0;
    void recur(int i,int j,int cnt,vector<vector<int>>& grid){
        if(grid[i][j]==2){
            if(nobs==cnt){
                ans++;
            }
            return ;
        }
        int ans=0;
        int save=grid[i][j];
        grid[i][j]=-1;
        if(i+1<grid.size()&&grid[i+1][j]!=-1){
            recur(i+1,j,cnt+1,grid);
        }
        if(i-1>=0&&grid[i-1][j]!=-1){
            recur(i-1,j,cnt+1,grid);
        }
        if(j+1<grid[0].size()&&grid[i][j+1]!=-1){
            recur(i,j+1,cnt+1,grid);
        }
        if(j-1>=0&&grid[i][j-1]!=-1){
            recur(i,j-1,cnt+1,grid);
        }
        grid[i][j]=save;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int starti;
        int startj;
        int endi;
        int endj;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    starti=i;
                    startj=j;
                }
                if(grid[i][j]==0){
                    nobs++;
                }
            }
        }
        recur(starti,startj,0,grid);
        return ans;
    }
};