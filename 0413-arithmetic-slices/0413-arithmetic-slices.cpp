class Solution {
public:
    int getVal(int val){
        int sum=0;
        while(val>0){
            sum+=val;
            val--;
        }
        return sum;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int prev=INT_MAX;
        int i=0;
        int j=1;
        int ans=0;
        while(j<nums.size()){
            int diff=nums[j]-nums[j-1];
            if(prev==INT_MAX){
                j++;
                prev=diff;
            }
            else if(prev==diff){
                j++;
                if(j==nums.size()){
                    if(j-i>=2){
                        int val=j-i;
                        ans+=getVal(val-2);
                    }
                }
                
            }
            else{
                if(j-i>=2){
                    int val=j-i;
                    ans+=getVal(val-2);
                }
                i=j-1;
                prev=diff;
                j++;
            }
        }
        return ans;
    }
};