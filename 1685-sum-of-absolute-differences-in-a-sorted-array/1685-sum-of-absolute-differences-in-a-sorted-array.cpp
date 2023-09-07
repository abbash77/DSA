class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int> suffix(n,0);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        for(int i=0;i<n;i++){
            //aage ka sum
            int aagesum=0;
            int s;
            if(i-1>=0){
                s=prefix[n-1]-prefix[i-1];
            }
            else{
                s=prefix[n-1];
            }
            aagesum=s-nums[i]*(n-i);
            //piche ka sum
            int t;
            if(i-1>=0){
                t=suffix[0]-suffix[i];
                
            }
            else{
                t=0;
            }
            int pichesum=nums[i]*(i)-t;
            ans.push_back(aagesum+pichesum);
        }
        return ans;
    }
};