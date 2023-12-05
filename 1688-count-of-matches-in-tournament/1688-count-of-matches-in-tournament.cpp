class Solution {
public:
    int numberOfMatches(int n) {
        int cnt=0;
        while(n>1){
            if(n&1){
                n=n/2;
                cnt+=n;
                n++;
            }
            else{
                n=n/2;
                cnt+=n;
            }
        }
        return cnt;
    }
};