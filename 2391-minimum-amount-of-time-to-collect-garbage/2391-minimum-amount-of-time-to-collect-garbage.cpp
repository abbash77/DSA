class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int sum=0;
       // travel[-1]=0;
        sum+=garbage[0].size();
        int sum2=0;int cntg=0;int cntp=0;int cntm=0;
        for(int i=1;i<garbage.size();i++){
            sum2+=travel[i-1];
            for(auto it:garbage[i]){
                if(it=='G'){
                    cntg=sum2;
                     
                }
                else if(it=='M'){
                   cntm=sum2;
                   
                }
                else{
                   cntp=sum2;
                   
                }

                sum++;
               
            }
            
        }
        sum+=(cntp+cntg+cntm);
     
        return sum;
    }
};