class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                    if(j&&k>0){
                        int a=-prices[i]+after[0][k];
                        int b=after[1][k];
                        curr[j][k]= max(a,b);
                    }
                    else if(j==0){
                        int a=prices[i]+after[1][k-1];
                        int b=after[0][k];
                        curr[j][k]= max(a,b);
                    }
                }
            }
            after=curr;
        }
        return curr[1][2];
    }
};