class Solution {
public:
    int MOD=1e9+7;
    int countNicePairs(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int rev_num = 0; 
            while (num > 0) { 
                rev_num = rev_num * 10 + num % 10; 
                num = num / 10; 
            } 
            nums[i]=nums[i]-rev_num;
        }
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        long long ans=0;
        for(auto val:m){
            int n=val.second-1;
            ans+=((long long)n*(n+1)/2)%MOD;
        }
        return ans%MOD;
    }
    
};