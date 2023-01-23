class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        bool minormax=true;
        while(nums.size()>1){
            vector<int> v;
            for(int i=0;i<nums.size();i=i+2){
                if(minormax){
                    v.push_back(min(nums[i],nums[i+1]));
                }
                else{
                    v.push_back(max(nums[i],nums[i+1]));   
                }
                minormax=!minormax;
            }
            nums=v;
            minormax=true;
        }
        return nums[0];
        
    }
};