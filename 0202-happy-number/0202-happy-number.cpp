class Solution {
public:
    int help(int n){
        int s=0;
        while(n>=10){
            int z=n%10;
            s+=pow(z,2);
            n=n/10;
        }
        s+=pow(n,2);
        return s;
        
    }
    bool isHappy(int n) {
        unordered_map<int,bool> loop;
        while(n!=1){
            if(loop.find(n)!=loop.end()){
                return false;
            }
            else{
               loop[n]=true; 
            }
            
            n=help(n);
        }
        return true;
    }
};