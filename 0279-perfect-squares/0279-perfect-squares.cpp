class Solution {
public:
     int minSteps(int n,int* memo){
        //Base Case
        if(n==0)
            return 0;
        
        if(memo[n]!=-1)return memo[n];
        //I will search for closest square to n
        int num=sqrt(n);
        int ans=INT_MAX;
        //I observed for minimum steps our num varies from sqrt(n) to sqrt(n)/2
        //As we can use numbers below sqrt(n)/2 in next function call
        while(num>=sqrt(n)/2){
            int op=minSteps(n-num*num,memo);
            ans=min(ans,op);
            if(op<=1)break; //If our op<=1 that will be always our minimum, we can observe that
            num--;
        }
        memo[n]=1+ans;
        return 1+ans;
    }
    int numSquares(int n) {
        int* memo=new int[n+1];
        for(int i=0;i<=n;i++){
            memo[i]=-1;
        }
        return minSteps(n,memo);
    }
};