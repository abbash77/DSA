class Solution {
public:
    bool isPossible(int a,int b,int r,int c,vector<vector<char>>& maze){
        if(a>=0&&a<r&&b>=0&&b<c&&maze[a][b]=='.'){
            return true;
        }
        return false;
    }
    bool isExit(int a,int b,int r,int c,vector<vector<char>>& maze,int x,int y){
            if(a==0||a==r-1||b==0||b==c-1){
                if(a==x&&b==y){
                    return false;
                }
                else{
                    return true;
                }
                
            }
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,pair<int,int>>> q;
        
        int x=entrance[0];
        int y=entrance[1];
        int r=maze.size();
        int c=maze[0].size();
        vector<vector<bool>> vis(r, vector<bool> (c,false));
        q.push({0,{entrance[0],entrance[1]}});
        vis[x][y]=true;
        int mini=INT_MAX;
        while(!q.empty()){
            auto j=q.front();
            auto i=j.second;
            auto step=j.first;
            if(isExit(i.first,i.second,r,c,maze,x,y)){
                if(step<mini){
                    mini=step;
                    break;
                }
            }
            q.pop();
            if(isPossible(i.first+1,i.second,r,c,maze)&&!vis[i.first+1][i.second]){
                int a=step;
                a++;
                vis[i.first+1][i.second]=true;
                q.push({a,{i.first+1,i.second}});
            }
            if(isPossible(i.first,i.second+1,r,c,maze)&&!vis[i.first][i.second+1]){
                int a=step;
                a++;
                vis[i.first][i.second+1]=true;
                q.push({a,{i.first,i.second+1}});
            }
            if(isPossible(i.first-1,i.second,r,c,maze)&&!vis[i.first-1][i.second]){
                int a=step;
                a++;
                vis[i.first-1][i.second]=true;
                q.push({a,{i.first-1,i.second}});
            }
            if(isPossible(i.first,i.second-1,r,c,maze)&&!vis[i.first][i.second-1]){
                int a=step;
                a++;
                vis[i.first][i.second-1]=true;
                q.push({a,{i.first,i.second-1}});
            }    
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};