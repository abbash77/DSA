class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        double sum=0;
        double ans=INT_MIN;
        while(j<nums.size()){
            if(j-i+1<k){
                sum+=nums[j];
                j++;
            }
            else{
                sum+=nums[j];
                ans=max(ans,(double)sum/double(k));
                sum-=nums[i];
                i++;
                j++;
                
            }
        }
        return ans;
    }
};