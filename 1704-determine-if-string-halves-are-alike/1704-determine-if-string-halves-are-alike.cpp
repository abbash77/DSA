class Solution {
public:
    bool isVowel(char k){
        if(k=='a'||k=='e'||k=='i'||k=='o'||k=='u'||k=='A'||k=='E'||k=='I'||k=='O'||k=='U'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int len=s.length();
        int cnt1=0;
        int cnt2=0;
       for(int i=0;i<s.length();i++){
           if(i<len/2){
               if(isVowel(s[i])){
                   cnt1++;
               }
           }
           else{
               if(isVowel(s[i])){
                   cnt2++;
               }
           }
       } 
        if(cnt1==cnt2){
            return true;
        }
        return false;
    }
};