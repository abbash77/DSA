class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        long long dist=sum-goal;
        dist=abs(dist);
        int ans=dist/limit;
        if(dist%limit!=0){
            ans+=1;
        }
        return ans;
    }
};