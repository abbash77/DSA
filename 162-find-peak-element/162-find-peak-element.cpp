class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxi=INT_MIN;
        int a=0;
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                a=i;
            }
        }
        return a;
    }
};