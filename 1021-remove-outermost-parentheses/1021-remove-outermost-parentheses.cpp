class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=0;
        string st="";
        for(int i=0;i<s.length();i++){
            if(n>0){
                if(n==1&&s[i]!=')'){
                    st+=s[i];
                }
                else if(n!=1){
                    st+=s[i];
                }
                
            }
            if(s[i]=='('){
                n++;
            }
            else{
                n--;
            }
        }
        return st;
    }
};