class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        for(int i=0;i<32;i++){
            long long val=pow(2,i);
            if(left<val&&val<right){
                return 0;
            }
        }
        long long ans=left;
        if(left<right){
            for(long long i=left+1;i<=right;i++){
                ans=ans&i;
            }
        }
        
        return ans;
        
    }
};