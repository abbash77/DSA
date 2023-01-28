class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul=1;
        int sum=0;
        while(n>0){
            int a=n%10;
            mul*=a;
            sum+=a;
            n=n/10;
        }
        return mul-sum;
    }
};