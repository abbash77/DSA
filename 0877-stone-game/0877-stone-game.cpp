class Solution {
public:
    bool helper(int start, int end, int turn, vector<int> &piles, int scorea, int scoreb, vector<vector<int>> &dp){

        if(start == end){
            if(turn == 0){
                scorea += piles[start];
            }else if(turn == 1){
                scoreb += piles[start];
            }
            if(scorea > scoreb) return true;
            return false;
        }

        if(dp[start][end] != -1) return dp[start][end];

        bool check = false;

        if(turn == 0){
            check = helper(start+1,end,1,piles,scorea+piles[start],scoreb,dp) || helper(start,end-1,1,piles,scorea+piles[end],scoreb,dp);
        }else if(turn == 1){
            check = helper(start+1,end,0,piles,scorea,scoreb+piles[start],dp) || helper(start,end-1,0,piles,scorea,scoreb+piles[end],dp);
        }

        return dp[start][end] = check;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return helper(0,n-1,0,piles,0,0,dp);
    }
};