class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int mini=INT_MAX;
        vector<int> ans(prices.size(),0);
        for(int i=0;i<prices.size();i++){
            int val=prices[i];
            int a=0;
            for(int j=i+1;j<prices.size();j++){
                if(val>=prices[j]){
                    ans[i]=val-prices[j];
                    a=1;
                    break;
                }
            }
            if(a==0){
                ans[i]=prices[i];
            }
            
            
        }
        return ans;
    }
};