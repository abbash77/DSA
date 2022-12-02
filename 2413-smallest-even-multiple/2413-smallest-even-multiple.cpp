class Solution {
public:
    int smallestEvenMultiple(int n) {
         int x;
        if(n%2==0){
            x=n;
        }
        else{
            x=2*n;
        }
        
        int ans=1;
        while(true){
            if(ans%x==0&&ans>=x){
                return ans;
            }
            ans++;
        }
    }
};