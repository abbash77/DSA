class Solution {
public:
    int func(string s, int k,char c){
        int i=0;
        int j=0;
        int cnt=0;
        int ans=0;
        while(j<s.length()){
            if(s[j]!=c){
                cnt++;
            }
            if(cnt>k){
                if(s[i]!=c){
                    cnt--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        vector<int> v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-'A']=1;
        }
        int maxi=0;
        for(int i=0;i<26;i++){
            if(v[i]==1){
                maxi=max(maxi,func(s,k,i+'A'));
            }
            
        }
        return maxi;
                         
        
    }
};