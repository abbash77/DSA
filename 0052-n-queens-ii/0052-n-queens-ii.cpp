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
    int helper(int n,vector<string> &board,int col){
        if(col==n){
            
            return 1;
        }
        int cnt=0;
        for(int r=0;r<n;r++){
            if(isPos(r,col,board,n)){
                board[r][col]='Q';
                cnt+=helper(n,board,col+1);
                board[r][col]='.';
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        int col=0;
        return helper(n,board,col);
    }
};