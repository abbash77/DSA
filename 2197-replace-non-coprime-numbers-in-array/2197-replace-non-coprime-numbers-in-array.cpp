 
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>arr;
        arr.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){   
            int val=arr.back();
            if(__gcd(val,nums[i])>1){
                arr.pop_back();
                int rem=lcm(val,nums[i]);
                while(!arr.empty() && __gcd(arr.back(),rem)>1){
                    rem=lcm(arr.back(),rem);
                    arr.pop_back();
                }
                arr.push_back(rem);
            }
            else{
                arr.push_back(nums[i]);
            }
        }
        return arr;
    }
};