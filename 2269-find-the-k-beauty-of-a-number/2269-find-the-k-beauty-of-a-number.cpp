class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int i=0;
        int j=0;
        string val=to_string(num);
        string s="";
        int cnt=0;
        while(j<val.size()){
            if(j-i+1<k){
                s+=val[j];
                j++;
            }
            else{
                s+=val[j];
                int v=stoi(s);
                if(v!=0&&num%v==0){
                    cnt++;
                }
                string s1="";
                for(int k=1;k<s.length();k++){
                    s1+=s[k];
                }
                s=s1;
                i++;
                j++;
            }
        }
        return cnt;
    }
};