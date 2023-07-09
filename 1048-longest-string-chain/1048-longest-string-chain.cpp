class Solution {
public:
    static bool cmp(string a,string b){
        return a.length()<b.length();
    }
    bool check(string a,string b){
        if(a.length()-1!=b.length()){
            return false;
        }
        int i=0;
        int j=0;
        while(i<a.length()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==a.length()&&j==b.length()){
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j])&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};