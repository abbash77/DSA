class Solution {
public:
    void dfs(vector<vector<int>>& board, int i, int j){
        if(i<0||i>=board.size()||j<0||j>=board[0].size())return;
        if(board[i][j]!=1)return;
        board[i][j]=2;
        dfs(board,i+1,j);
        dfs(board,i,j+1);
        dfs(board,i-1,j);
        dfs(board,i,j-1);
        return;
    }
    int numEnclaves(vector<vector<int>>& board) {
        // if(board.size()==0||board[0].size()==0)return;
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]==1){dfs(board,0,i);}
            if(board[board.size()-1][i]==1){dfs(board,board.size()-1,i);}
        }
        for(int i=1;i<board.size()-1;i++){
            if(board[i][0]==1)dfs(board,i,0);
            if(board[i][board[0].size()-1]==1){dfs(board,i,board[0].size()-1);}
        }
        int cnt=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
};