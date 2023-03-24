class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long cnt=1;
        long long ans=prices.size();
        
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]-prices[i+1]==1){
                cnt++;
            }
            else{
                ans+=(cnt*(cnt+1))/2-cnt;
                cnt=1;
            }
        }
        ans+=(cnt*(cnt+1))/2-cnt;
        return ans;
    }
};