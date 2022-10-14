class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        int ans=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int i=front.first;
            int j=front.second;
            if(i==-1){
                ans+=1;
                if(!q.empty()){
                    q.push({-1,-1});
                }
                
                continue;
            }
            if(i-1>=0&&grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({i-1,j});
            }
            if(i+1<grid.size()&&grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({i+1,j});
            }
            if(j-1>=0&&grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({i,j-1});
            }
            if(j+1<grid[0].size()&&grid[i][j+1]==1){
                grid[i][j+1]=2;
                q.push({i,j+1});
            }
            
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans-1;
    }
};