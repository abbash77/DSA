class Solution {
public:
    bool isPos(int row,int col,vector<string> board,int n){
        int drow=row;
        int dcol=col;
        while(row>=0&&col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        col=dcol;
        row=drow;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        col=dcol;
        row=drow;
        while(col>=0&&row<n){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void helper(int n,vector<string> &board,vector<vector<string>>& ans,int col){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int r=0;r<n;r++){
            if(isPos(r,col,board,n)){
                board[r][col]='Q';
                helper(n,board,ans,col+1);
                board[r][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        int col=0;
        helper(n,board,ans,col);
        return ans;
    }
};