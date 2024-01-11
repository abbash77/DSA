class Solution {
public:
    int longestBeautifulSubstring(string word) {
        char prev='x';
        unordered_map<char,int> m;
        m['a']=0;
        m['e']=0;
        m['i']=0;
        m['o']=0;
        m['u']=0;
        int cnt=0;
        int ans=0;
        for(int i=0;i<word.size();i++){
            if(prev=='x'){
                cnt++;
                prev=word[i];
                m[word[i]]=1;
            }
            else if(prev>word[i]){
                cnt=1;
                m['a']=0;
                m['e']=0;
                m['i']=0;
                m['o']=0;
                m['u']=0;
                m[word[i]]=1;
                prev=word[i];
            }
            else{
                m[word[i]]=1;
                prev=word[i];
                cnt++;
                int a=0;
                for(auto j:m){
                    if(j.second!=1){
                        a=1;
                        break;
                    }
                }
                if(a==0){
                    ans=max(ans,cnt);
                }
            }
            
        }
        return ans;
    }
};