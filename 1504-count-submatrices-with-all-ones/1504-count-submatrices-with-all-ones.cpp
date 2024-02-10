class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++){
            int sum=0;
            for(int j=mat[0].size()-1;j>=0;j--){
                if(mat[i][j]==1){
                    sum++;
                    mat[i][j]=sum;
                }
                else{
                    sum=0;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int mini=INT_MAX;
                for(int k=i;k<mat.size();k++){
                    mini=min(mini,mat[k][j]);
                    cnt+=mini;
                }
            }
        }
        return cnt;
    }
};