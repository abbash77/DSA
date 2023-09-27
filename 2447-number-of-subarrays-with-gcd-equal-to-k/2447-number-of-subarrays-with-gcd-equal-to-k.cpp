class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int i = 0 , j = 0;
        int div = nums[0];

        while(j < nums.size())
        {
            div = __gcd(nums[j] , nums[j++]);
                if(div == k)ans++;
            while(j < nums.size() && div >= k)
            {
                div = __gcd(div , nums[j++]);
                if(div == k)ans++;
            }
            i++;
            j=i;
            
        }
        return ans;
    }
};