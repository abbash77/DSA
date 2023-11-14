class Solution {
public:
    int MOD=1e9+7;
    int countHomogenous(string s) {
        int i=0;
        int j=0;
        long long ans=0;
        while(j<s.length()){
            if(s[i]==s[j]){
                j++;
            }
            else{
                int n=0;
                n=j-i;
                ans+=(((long long)n*(n+1)%MOD)/2)%MOD;
                i=j;
                j++;
            }
        }
        int n;
        n=j-i;
        ans+=(((long long)n*(n+1)%MOD)/2)%MOD;
        return ans;
    }
};