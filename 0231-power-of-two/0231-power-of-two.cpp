class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i=0;
        while(true){
            if(pow(2,i)==n){
                return true;
            }
            if(pow(2,i)>n){
                break;
            }
            i++;
        }
        return false;
        
    }
};