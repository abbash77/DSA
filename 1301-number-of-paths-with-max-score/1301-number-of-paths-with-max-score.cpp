class Solution {
public:
    int MOD=1e9+7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        int n=board.size();
        int m=board[0].size();
        vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(m+1,{0,0}));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==1&&j==1){
                    dp[i][j]={0,1};
                }
                else if(i==0||j==0||board[i-1][j-1]=='X'){
                    dp[i][j]={INT_MIN,0};
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1&&j==1){
                    continue;
                }
                if(board[i-1][j-1]=='X'){
                    continue;
                }
                pair<int,int> a=dp[i-1][j-1];
                pair<int,int> b=dp[i-1][j];
                pair<int,int> c=dp[i][j-1];
                int cnt=0;
                int maxi=max({a.first,b.first,c.first})%MOD;
                if(maxi==a.first){
                    cnt+=a.second;
                }
                if(maxi==b.first){
                    cnt+=b.second;
                }
                if(maxi==c.first){
                    cnt+=c.second;
                }
                int ans=0;
                if(board[i-1][j-1]!='S'){
                    ans=board[i-1][j-1]-'0';
                }
                dp[i][j]= {(ans+maxi)%MOD,cnt%MOD};
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<dp[i][j].first<<" "<<dp[i][j].second<<"  ";
        //     }
        //     cout<<endl;
        // }
        pair<int,int> p=dp[n][m];
        vector<int> ans;
        ans.push_back(p.first%MOD);
        ans.push_back(p.second%MOD);
        if(p.second==0){
            return {0,0};
        }
        return ans;
    }
};