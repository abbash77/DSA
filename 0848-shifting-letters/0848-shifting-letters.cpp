class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long n=shifts.size();
        vector<long long> suffix(n,0);
        suffix[n-1]=shifts[n-1];
        for(long long i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+shifts[i];
        }
        for(long long i=0;i<shifts.size();i++){
            suffix[i]=suffix[i]%26;
            if(s[i]+suffix[i]>'z'){
                int diff=s[i]+suffix[i]-'z';
                s[i]='a'+diff-1;
            }else{
                s[i]=s[i]+suffix[i];
            }
            
        }
        return s;
    }
};