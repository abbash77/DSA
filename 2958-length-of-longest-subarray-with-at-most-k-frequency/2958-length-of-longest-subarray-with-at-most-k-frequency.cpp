class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        unordered_map<int,int> m;
        int maxi=0;
        while(j<nums.size()){
            if(m.find(nums[j])!=m.end()){
                int val=m[nums[j]];
                if(val==k){
                    while(nums[i]!=nums[j]){
                        m[nums[i]]--;
                        i++;
                    }
                    j++;
                    i++;
                }
                else{
                    int ans=j-i+1;
                    maxi=max(maxi,ans);
                    m[nums[j++]]++;
                    
                }
            }
            else{
                int ans=j-i+1;
                maxi=max(maxi,ans);
                m[nums[j++]]++;
                
            }
        }
        return maxi;
    }
};