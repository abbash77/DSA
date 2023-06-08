class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int i=0;
        int j=n-1;
        int cnt=0;
        while(j>=0&&i<m){
            if(grid[i][j]<0){
                cnt+=m-i;
                j=j-1;
            }
            else{
                i=i+1;
            }
        }
        return cnt;
    }
};