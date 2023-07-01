class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n=nums.size();
        int a=nums[0];
        int b=0;
        for(int i=1;i<n-1;i++){
            int p=nums[i];
            if(i>1){
                p+=b;
            }
            int n=a;
            b=a;
            a=max(p,n);
        }
        
        
        int x=nums[1];
        int y=0;
        for(int i=2;i<n;i++){
            int p=nums[i];
            if(i>1){
                p+=y;
            }
            int n=x;
            y=x;
            x=max(p,n);
        }
        return max(x,a);
    }
};