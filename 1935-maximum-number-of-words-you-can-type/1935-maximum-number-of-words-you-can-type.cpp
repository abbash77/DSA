class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,bool> m;
        int a=1;
        int c=0;
        for(int i=0;i<brokenLetters.length();i++){
            m[brokenLetters[i]]=true;
        }
        for(int i=0;i<text.length();i++){
            if(m[text[i]]){
                a=0;
            }
            if(text[i]==' '){
                if(a==1){
                    c++;
                }
                a=1;
            }
        }
        if(a==1){
            c++;
        }
        return c;
    }
};