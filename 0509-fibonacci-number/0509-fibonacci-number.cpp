class Solution {
public:
    int fib(int n) {
        if(n==0||n==1){
            return n;
        }
        vector<int> d(n+1);
        d[0]=0;
        d[1]=1;
        for(int i=2;i<=n;i++){
            d[i]=d[i-1]+d[i-2];
        }
        return d[n];
    }
};