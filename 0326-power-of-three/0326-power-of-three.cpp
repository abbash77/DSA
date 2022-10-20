class Solution {
public:
    bool isPowerOfThree(int n) {
        int i=0;
        while(true){
            if(pow(3,i)==n){
                return true;
            }
            if(pow(3,i)>n){
                break;
            }
            i++;
        }
        return false;
    }
};