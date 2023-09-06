class Solution {
public:
    int coutNeighbour(int i,int j,vector<vector<int>>& board){
        int n=board.size();
        int m=board[0].size();
        int cnt=0;
        if(i-1>=0&&(board[i-1][j]==1||board[i-1][j]==-1)){
            cnt++;
        }
        if(j-1>=0&&(board[i][j-1]==1||board[i][j-1]==-1)){
            cnt++;
        }
        if(i+1<n&&(board[i+1][j]==1||board[i+1][j]==-1)){
            cnt++;
        }
        if(j+1<m&&(board[i][j+1]==1||board[i][j+1]==-1)){
            cnt++;
        }
        if(i-1>=0&&j-1>=0&&(board[i-1][j-1]==1||board[i-1][j-1]==-1)){
            cnt++;
        }
        if(i-1>=0&&j+1<m&&(board[i-1][j+1]==1||board[i-1][j+1]==-1)){
            cnt++;
        }
        if(i+1<n&&j-1>=0&&(board[i+1][j-1]==1||board[i+1][j-1]==-1)){
            cnt++;
        }
        if(i+1<n&&j+1<m&&(board[i+1][j+1]==1||board[i+1][j+1]==-1)){
            cnt++;
        }
        cout<<cnt<<endl;
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int totalNeigh=coutNeighbour(i,j,board);
                if(board[i][j]==0&&totalNeigh==3){
                    board[i][j]=2;
                }
                else if(board[i][j]==1){
                    if(totalNeigh==1||totalNeigh==0){
                        
                        board[i][j]=-1;
                    }
                    else if(totalNeigh==2||totalNeigh==3){
                        board[i][j]=1;
                    }
                    else if(totalNeigh>=4){
                        board[i][j]=-1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==-1){
                    board[i][j]=0;
                }
                else if(board[i][j]==2){
                    board[i][j]=1;
                }
            }
        }
        
    }
};