class Solution {
public:
    string replaceDigits(string s) {
        for(int i=1;i<s.length();i=i+2){
            int a=s[i]-48;
            s[i]=s[i-1]+a;
        }
        return s;
    }
};