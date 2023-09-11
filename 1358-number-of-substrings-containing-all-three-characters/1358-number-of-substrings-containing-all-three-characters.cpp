class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnta=0;
        int cntb=0;
        int cntc=0;
        int n=s.length();
        int ans=0;
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                cnta++;
            }
            else if(s[i]=='b'){
                cntb++;
            }
            else if(s[i]=='c'){
                cntc++;
            }
            if(cnta>=1&&cntb>=1&&cntc>=1){
                ans+=n-i;
                while(j<=i){
                    if(s[j]=='a'){
                        cnta--;
                    }
                    else if(s[j]=='b'){
                        cntb--;
                    }
                    else if(s[j]=='c'){
                        cntc--;
                    }
                    j++;
                    if(cnta>=1&&cntb>=1&&cntc>=1){
                        ans+=n-i;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};