class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum;
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            int s=i+1;
            int e=nums.size()-1;
            while(s<e){
                int a=nums[i]+nums[s]+nums[e];
                if(abs(ans-target)>abs(a-target)){
                    ans=a;
                }
                if(a==target){
                    break;
                }
                if(a>target){
                    e--;
                }
                else{
                    s++;
                }
                
            }
            
            
        }
        return ans;
    }
};