class Solution {
public:
    int dp[71][71][71];

int func(vector<vector<int>>&grid,int r1,int c1,int c2){
    
    int r2=r1;
    
    if(r1>=grid.size() || r2>=grid.size() || c1<0 || c2<0 || c1>=grid[0].size() || c2>=grid[0].size()){
        return INT_MIN;
    }
    
    if(dp[r1][c1][c2]!=-1){
        return dp[r1][c1][c2];
    }
    
    
    if(r1==grid.size()-1){
        
        if(c1==c2){
            return grid[r1][c1];
        }
        
        else{
            return grid[r1][c1]+grid[r1][c2];
        }
        
    }
    
    
    int cherry=0;
    
    if(c1==c2){
        cherry+=grid[r1][c1];
    }

    
    else{
        cherry+=grid[r1][c1];
        cherry+=grid[r1][c2];
    }
    
    
    int maxcherry=0;
    
    for(int i=-1;i<=1;i++){
        
        for(int j=-1;j<=1;j++){
            
            maxcherry=max(maxcherry,func(grid,r1+1,c1+i,c2+j));
            
        }
        
    }
    
    return dp[r1][c1][c2]=cherry+maxcherry;
    
}

int cherryPickup(vector<vector<int>>& grid) {
    
    int m=grid.size();
    int n=grid[0].size();
    
    memset(dp,-1,sizeof(dp));
    
    int ans=func(grid,0,0,n-1);
    
    return ans;
    
}
};