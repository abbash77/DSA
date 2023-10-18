class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int z=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    grid[i][j]=2;
                    z++;
                }
                
            }
        }
        if(z==m*n){
            return -1;
        }
        int maxi=-1;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto front=q.front();
                q.pop();
                int i=front.first.first;
                int j=front.first.second;
                int val=front.second;
                maxi=max(val,maxi);
                if(i-1>=0&&grid[i-1][j]!=2){
                    grid[i-1][j]=2;
                    q.push({{i-1,j},val+1});
                }
                if(j-1>=0&&grid[i][j-1]!=2){
                    grid[i][j-1]=2;
                    q.push({{i,j-1},val+1});
                }
                if(i+1<n&&grid[i+1][j]!=2){
                    grid[i+1][j]=2;
                    
                    q.push({{i+1,j},val+1});
                }
                if(j+1<m&&grid[i][j+1]!=2){
                    grid[i][j+1]=2;
                    
                    q.push({{i,j+1},val+1});
                }
            }
            
            
        }
        return maxi;
        
    }
};