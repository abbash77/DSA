class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int flag=0;
      for(int i=0;i<grid.size();i++){
          for(int j=0;j<grid[0].size();j++){
              if(grid[i][j]==2){
                q.push({i,j});
                visited[i][j]=true;
              }
              if(grid[i][j]==1){
                  flag=1;
              }
            
          }
      }
        if(flag==0){
            return 0;
        }
        int time=0;
      while(!q.empty()){
          int n=q.size();
          for(int i=0;i<n;i++){
               pair<int,int> top=q.front();
               q.pop();
              
               int a=top.first;
               int b=top.second;
              //visited ,1,boundry
              
               if(a-1>=0 && grid[a-1][b]==1 && !visited[a-1][b]){
                   grid[a-1][b]=2;
                   visited[a-1][b]=true;
                  q.push({a-1,b});
               }
              if(b-1>=0 && grid[a][b-1]==1 && !visited[a][b-1]){
                  visited[a][b-1]=true;
                  q.push({a,b-1});
                   grid[a][b-1]=2;
              }
              if(a+1<grid.size() && grid[a+1][b]==1 && !visited[a+1][b]){
                  visited[a+1][b]=true;
                  q.push({a+1,b});
                   grid[a+1][b]=2;
              }
              if(b+1<grid[0].size()&& grid[a][b+1]==1 && !visited[a][b+1]){
                  visited[a][b+1]=true;
                  q.push({a,b+1});
                   grid[a][b+1]=2;
              }
              
          }
          time++;
         
      }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time-1;
    }
};