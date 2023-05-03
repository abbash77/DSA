class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        while(target!=1){
            if(target%2!=0&&maxDoubles>0){
                ans=ans+2;
                target=target/2;
                maxDoubles--;
            }
            else if(target%2==0&&maxDoubles>0){
                ans=ans+1;
                target=target/2;
                maxDoubles--;
            }
            else{
                ans+=target-1;
                break;
            }
        }
        return ans;
    }
};