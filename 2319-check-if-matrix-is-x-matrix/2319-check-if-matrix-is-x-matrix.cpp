class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        map<pair<int,int>,bool> m;
        int k=0;
        for(int i=n-1;i>=0;i--){
            m[{i,k}]=true;
            k++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    if(grid[i][j]==0){
                        return false;
                    }
                }
                else if(m[{i,j}]){
                    if(grid[i][j]==0){
                        return false;
                    }
                }
                else{
                    if(grid[i][j]!=0){
                        return false;
                    }
                }
                
            }
           
        }
         return true;
    }
};