class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,pair<int,int>>> q;
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j]==1){
                    visited[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        
        while(!q.empty()){
            pair<int,pair<int,int>> front=q.front();
            q.pop();
            int val=front.first;
            int i=front.second.first;
            int j=front.second.second;
            isWater[i][j]=val;
            int r[4]={-1,0,+1,0};
            int c[4]={0,+1,0,-1};
            val++;
            for(int k=0;k<4;k++){
                int newi=i+r[k];
                int newj=j+c[k];
                if(newi>=0&&newj>=0&&newi<n&&newj<m&&!visited[newi][newj]){
                    visited[newi][newj]=1;
                    q.push({val,{newi,newj}});
                }
            }
        }
        return isWater;           
    }
};