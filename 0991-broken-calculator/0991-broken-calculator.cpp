class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cnt=0;
        while(startValue<target){
            if(target%2!=0){
                target=(target+1)/2;
                cnt+=2;
                
            }
            else{
                target=target/2;
                cnt+=1;
            }
        }
        return cnt+(startValue-target);
    }
};