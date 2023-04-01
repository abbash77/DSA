class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long ans=0;
        ans+=customers[0][1];
        int x=customers[0][0]+customers[0][1];
        for(int i=1;i<customers.size();i++){
            if(customers[i][1]+x-customers[i][0]>=0&&x>customers[i][0]){
                ans+=customers[i][1]+x-customers[i][0];
                x+=customers[i][1];
            }
            else{
                ans+=customers[i][1];
                x=customers[i][0]+customers[i][1];
            }
        }
        return (double)ans/(double)customers.size();
        return ans;
    }
};