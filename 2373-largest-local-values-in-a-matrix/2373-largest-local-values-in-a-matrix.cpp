class Solution {
public:
    int maxi(int x,int y,vector<vector<int>>& grid){
        int maxii=INT_MIN;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                maxii=max(maxii,grid[i+x][j+y]);
            }
        }
        return maxii;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        int it=(n-2)*(n-2);
        vector<vector<int>> ans;
        vector<int> a;
        int j=0;
        for(int i=0;i<n-2;i++){
            while(j<n-2){
                int maxii=maxi(i,j,grid);
                a.push_back(maxii);
                j++;
            }
            ans.push_back(a);
            a.clear();
            j=0;
        }
        return ans;
    }
};