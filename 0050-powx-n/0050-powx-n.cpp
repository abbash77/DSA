class Solution {
public:
    double myPow(double x, int n) {
       double ans=1;
        long neg=n;
        if(neg<0){
            neg=neg*-1;
        }
        while(neg>0){
            if(neg%2==0){
                x=x*x;
                neg=neg/2;
            }
            else{
                ans=ans*x;
                neg=neg-1;
                
            }
        }
        if(n<1){
            return (double)1.0/(double)ans;
        }
        return ans;  
    }
};