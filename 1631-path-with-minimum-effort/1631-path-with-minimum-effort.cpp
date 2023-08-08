class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
                priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int> > > > pq;
        int n=heights.size();
        int m=heights[0].size();
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            int weight=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1&&y==m-1){
                return weight;
            }
            for(int i=0;i<4;i++){
                int nr=x+dr[i];
                int nc=y+dc[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m){
                    int newEffort=max(abs(heights[nr][nc]-heights[x][y]),weight);
                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc]=newEffort;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                    
                }
            }
            
        }
        return 0;
    }
};