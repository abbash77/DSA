class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int j=0;
        int sum=0;
        for(int i=0;i<mat.size();i++){
            sum+=mat[i][j];
            j++;
        }
        int k=0;
        for(int i=mat.size()-1;i>=0;i--){
            if(i!=k){
                sum+=mat[i][k];
            }
            
            k++;
        }
        return sum;
    }
};