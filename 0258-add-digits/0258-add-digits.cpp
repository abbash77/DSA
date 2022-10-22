class Solution {
public:
    int addDigits(int num) {
        int z=num;
        while(num>=10){
            num=z;
            int a=0;
            while(num>=10){
                a+=num%10;
                num=num/10;
            }
            a+=num;
            z=a;
            num=a;
        }
        return num;
        
    }
};