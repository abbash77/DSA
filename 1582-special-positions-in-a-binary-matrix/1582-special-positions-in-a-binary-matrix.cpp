class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row;
        int r=mat.size();
        int c=mat[0].size();
        for(int i=0;i<r;i++){
            int cnt=0;
            for(int j=0;j<c;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            row.push_back(cnt);
        }
        vector<int> col;
        for(int i=0;i<c;i++){
            int cnt=0;
            for(int j=0;j<r;j++){
                if(mat[j][i]==1){
                    cnt++;
                }
            }
            col.push_back(cnt);
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==1&&row[i]<=1&&col[j]<=1){
                    ans++;
                }
            }
        }
        return ans;
    }
};