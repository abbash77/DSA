class Solution {
public:
    bool isPowerOfFour(int n) {
        int i=0;
        while(true){
            if(pow(4,i)==n){
                return true;
            }
            if(pow(4,i)>n){
                break;
            }
            i++;
        }
        return false;
    }
};