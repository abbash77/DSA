class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int val=0;
        int ans=1;
       for(int i=0;i<nums.size()-1;i++){
           if((val==0||val==1)&&nums[i+1]-nums[i]>0){
               val=-1;
               ans++;
           }
           else if((val==0||val==-1)&&nums[i+1]-nums[i]<0){
               val=1;
               ans++;
           }
       }
        return ans;
    }
};