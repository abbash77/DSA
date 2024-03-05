class Solution {
public:
    int minimumLength(string s) {
        //2 1 1 2 1 1 2 1 1
        int n=s.length();
        vector<int> suffix(n,1);
        for(int i=n-2;i>=0;i--){
            if(s[i+1]==s[i]){
                suffix[i]=suffix[i+1]+1;
            }
        }
        vector<int> prefix(n,1);
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]){
                prefix[i]=prefix[i-1]+1;
            }
        }
        
        int i=0;
        int j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                i+=suffix[i];
                j-=prefix[j];
            }
            else{
                break;
            }
        }
        if(j-i<0){
            return 0;
        }
        return j-i+1;
        
    }
};