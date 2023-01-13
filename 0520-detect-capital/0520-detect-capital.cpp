class Solution {
public:
    bool detectCapitalUse(string word) {
         int count=0;
        if(word[0]>=97 && word[0]<123){
            for(int i=1;i<word.length();i++){
                if(word[i]>=65 && word[i]<91){
                    return false;
                }
            }
        }
        if(word[0]>=65 && word[0]<91){
            for(int i=1;i<word.length();i++){
                if(word[i]>=65 && word[i]<91){
                    count++;
                }
            }
        }
        if(count==0 || count==word.length()-1){
            return true;
        }
        else{
            return false;
        }
    }
};