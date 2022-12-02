class Solution {
public:
    int countAsterisks(string s) {
         int count=0;
        int a=0;
       for(int i=0;i<s.length();i++){
           if(s[i]=='|' && a==0){
               a=1;
           }
           else if(s[i]=='|' && a==1){
               a=0;
           }
           else{
               if(a==0 && s[i]=='*'){
                   count++;
               }
           }
       }
        return count;
    }
};