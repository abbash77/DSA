class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        





int i=0;
        int j=0;
        long long count=0;
        int a=-1;
        while(j<nums.size()){
            if(j<nums.size()-1 && nums[j]!=nums[j+1]){    
               
                j++;
            }
            else{
                
                j++;
                i=j;
                
                
            }
             count+=j-i+1; 
        }
        return count;
    }
};