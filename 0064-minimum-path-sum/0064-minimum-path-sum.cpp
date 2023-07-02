class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
    int n=grid[0].size();
    vector<int> prev(n,-1);
    for(int i=0;i<grid.size();i++){
        vector<int> cur(n,0);
        for(int j=0;j<grid[0].size();j++){
            if(i==0&&j==0){
                cur[0]=grid[0][0];
            }
            else{
                int a=INT_MAX;
                int b=INT_MAX;
                if(i>0){
                    a=prev[j];
                }
                if(j>0){
                    b=cur[j-1];
                }
                cur[j]=grid[i][j]+min(a,b);
            }
        }
        prev=cur;
    }
    return prev[n-1];
    }
};