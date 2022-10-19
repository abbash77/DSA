class Solution {
public:
    int lengthOfLastWord(string s) {
        string str="";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                while(s[i]!=' '){
                    str+=s[i];
                    if(i==0){
                        break;
                    }
                    i--;
                }
                break;
            }
           
        }
        return str.length();
    }
};