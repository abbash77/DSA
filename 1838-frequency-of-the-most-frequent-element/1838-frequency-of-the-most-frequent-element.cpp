class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1){
            return 1;
        }
        int i=nums.size()-1;
        int j=i-1;
        int maxAns=-1;
        int ans=0;
        while(i>=0){
            int diff=nums[i]-nums[j];
            if(diff<=k){
                j--;
                ans=i-j;
                maxAns=max(ans,maxAns);
                k-=diff;
            }
            else{
                int diff2=nums[i]-nums[i-1];
                i--;
                k+=diff2*(i-j);
            }
            if(j==-1){
                break;
            }
        }
        return maxAns;
    }
};