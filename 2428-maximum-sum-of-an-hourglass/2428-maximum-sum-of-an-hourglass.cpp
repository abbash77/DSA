class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int ans=INT_MIN;
        int c=grid[0].size();
        for(int i=0;i<r-2;i++){
            for(int j=0;j<c-2;j++){
                int val=j;
                int sum=0;
                int a=0;
                for(int k=j;k<j+3;k++){
                    a++;
                    if(a==1){
                        sum+=grid[i][k];
                        sum+=grid[i+2][k];
                    }
                    else if(a==2){
                        sum+=grid[i][k];
                        sum+=grid[i+1][k];
                        sum+=grid[i+2][k];
                    }
                    else if(a==3){
                        sum+=grid[i][k];
                        sum+=grid[i+2][k];
                    }
                }
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};