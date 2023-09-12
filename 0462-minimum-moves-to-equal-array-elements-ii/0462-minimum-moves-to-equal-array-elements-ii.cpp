class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MAX;
        int sum=0;
        if(n%2!=0){
            int a=n/2;
            for(int i=0;i<n;i++){
                sum+=abs(nums[a]-nums[i]);
            }
            ans=sum;
        }
        else{
            int a=n/2-1;
            sum=0;
            for(int i=0;i<n;i++){
                sum+=abs(nums[a]-nums[i]);
            }
            ans=sum;
            a++;
            sum=0;
            for(int i=0;i<n;i++){
                sum+=abs(nums[a]-nums[i]);
            }
            ans=min(ans,sum);
            
        }
        return ans;
        
    }
};