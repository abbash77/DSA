class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& mat) {
        
        int r=mat.size();
        int c=mat[0].size();
        vector<int> row(r,0);
        for(int i=0;i<r;i++){
            int cnt=0;
            for(int j=0;j<c;j++){
                if(mat[i][j]==1){
                    row[i]+=1;
                }
                else{
                    row[i]-=1;
                }
            }
            
        }
        vector<int> col(c,0);
        for(int i=0;i<c;i++){
            int cnt=0;
            for(int j=0;j<r;j++){
                if(mat[j][i]==1){
                    col[i]+=1;
                }
                else{
                    col[i]-=1;
                }
            }
        }
        vector<vector<int>> ans(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j]+=row[i]+col[j];
            }
        }
        return ans;
    }
};