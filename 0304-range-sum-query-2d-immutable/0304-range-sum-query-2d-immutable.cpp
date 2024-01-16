class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        prefix.resize(n, vector<int>(m,0));
        prefix[0][0]=matrix[0][0];
        for(int i=1;i<n;i++){
            prefix[i][0]=prefix[i-1][0]+matrix[i][0];
        }
        for(int i=1;i<m;i++){
            prefix[0][i]=prefix[0][i-1]+matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]+matrix[i][j]-prefix[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<prefix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1-1>=0&&col1-1>=0){
            return prefix[row2][col2]+prefix[row1-1][col1-1]-prefix[row1-1][col2]-prefix[row2][col1-1];
        }
        else if(row1-1>=0){
            return prefix[row2][col2]-prefix[row1-1][col2];
        }
        else if(col1-1>=0){
            return prefix[row2][col2]-prefix[row2][col1-1];
        }
        return prefix[row2][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */