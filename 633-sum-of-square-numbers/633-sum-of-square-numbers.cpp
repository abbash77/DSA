class Solution {
public:
    bool judgeSquareSum(int c) {
        long e=sqrt(c);
        long s=0;
        long mid=e*e+s*s;
        bool ans=false;
        while(s<=e){
            if(mid==c){
                ans=true;
                break;
            }
            else if(mid>c){
                e=e-1;
            }
            else{
                s=s+1;
            }
            mid=e*e+s*s;
            
        }
        return ans;
    }
};