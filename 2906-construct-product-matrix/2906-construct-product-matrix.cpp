class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> left(n,vector<int>(m,1));
        vector<vector<int>> right(n,vector<int>(m,1));
        int prev=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                left[i][j]=prev;
                prev=(((prev)%12345)*((grid[i][j])%12345))%12345;
            }
        }
        int last=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                right[i][j]=last;
                last=(((last)%12345)*((grid[i][j])%12345))%12345;
            }
        }
        vector<vector<int>> result(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[i][j]=(left[i][j]*right[i][j])%12345;
            }
        }
        return result;
    }
};