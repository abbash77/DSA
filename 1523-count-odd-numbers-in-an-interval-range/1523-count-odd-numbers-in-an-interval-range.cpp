class Solution {
public:
    int countOdds(int low, int high) {
        int ans=0;
        // for(int i=low;i<=high;i++){
        //     if(i%2!=0){
        //         ans++;
        //     }
        // }
        int total=high-low+1;
        
        if(low%2!=0&&high%2!=0){
            if(total==1){
                return 1;
            }    
            ans+=2;
            ans+=(total-2)/2;
        }
        else if(low%2==0&&high%2==0){
            ans+=total/2;
        }
        else{
            ans+=(total-2)/2;
            ans+=1;
        }
        
        return ans;
    }
};