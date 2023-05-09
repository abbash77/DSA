class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int count=0;
        int total=row*col;
        int startRow=0;
        int startCol=0;
        int endingRow=row-1;
        int endingCol=col-1;
        while(count<total){
            //printing starting row
            for(int i=startCol;count<total&&i<=endingCol;i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            //printing ending col
            for(int i=startRow;count<total&&i<=endingRow;i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            //printing ending row
            for(int i=endingCol;count<total&&i>=startCol;i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            //printing starting col
            for(int i=endingRow;count<total&&i>=startRow;i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};