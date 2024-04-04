class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int n=numBottles;
        int count=0;
        if(numBottles>=numExchange){
             while(numBottles>=numExchange){
                numBottles-=numExchange;
                count++;
                
                // numBottles++;
                
                numExchange++;
            }
        }
        
         if(count+numBottles>=numExchange){
            numBottles+=count;
          while(numBottles>=numExchange){
                numBottles-=numExchange;
                count++;
                cout<<"k"<<endl;
                cout<<count<<endl;
                // numBottles++;
                
                numExchange++;
            }
        }
       
        return n+count;
        
    }
};