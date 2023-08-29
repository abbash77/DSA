class Solution {
public:
    int bestClosingTime(string customers) {
        int cntY=0;
        int cntN=0;
        for(int i=0;i<customers.length();i++){
            if(customers[i]=='Y'){
                cntY++;
            }
            else{
                cntN++;
            }
        }
        int N=cntN;
        
        int idx=0;
        int mini=INT_MAX;
        for(int i=0;i<customers.length();i++){
            int a=cntY+(N-cntN);
            if(a<mini){
                mini=a;
                idx=i;
            }
            if(customers[i]=='Y'){
                cntY--;
            }
            else{
                cntN--;
            }
            
            
        }
        if(N<mini){
            cout<<mini;
            return customers.length();
        }
        return idx;
    }
};