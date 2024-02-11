class Solution {
public:
    
    int func(int i1,int j1,int i2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
       int j2=i1+j1-i2; if(i1>=grid.size()||i2>=grid.size()||j1>=grid.size()||j2>=grid.size()||grid[i1][j1]==-1||grid[i2][j2]==-1){
            return INT_MIN;
        }
        
        int ans=0;
        if(i1==grid.size()-1 && j1==grid.size()-1){
             return grid[i1][j1];
        }
        if(dp[i1][j1][i2]!=-1){
            return dp[i1][j1][i2];
        }
        if(i1==i2&&j1==j2){
            ans+=grid[i1][j1];
        }
        else{
            ans+=grid[i1][j1];
            ans+=grid[i2][j2];
        }
        
        int dir1=func(i1+1,j1,i2+1,grid,dp);
        int dir2=func(i1+1,j1,i2,grid,dp);
        int dir3=func(i1,j1+1,i2+1,grid,dp);
        int dir4=func(i1,j1+1,i2,grid,dp);
        return dp[i1][j1][i2]= ans+max({dir1,dir2,dir3,dir4});
        
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,func(0,0,0,grid,dp));
    }
};