class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            else{
                maxi=max(maxi,sum);
            }
        }
        int sum1=0;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum1+=nums[i];
            if(sum1>0){
                sum1=0;
            }
            else{
                mini=min(mini,sum1);
            }
        }
        if(mini==INT_MAX){
            return maxi;
        }
        if(maxi==INT_MIN){
            return abs(mini);
        }
        
        mini=abs(mini);
        if(mini>maxi){
            return mini;
        }
        return maxi;
    }
};