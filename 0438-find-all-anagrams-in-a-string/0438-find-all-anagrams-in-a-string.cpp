class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> v(26,0);
        set<char> set1;
        int n=p.length();
        for(int i=0;i<p.length();i++){
            v[p[i]-'a']++;
            set1.insert(p[i]);
        }
        vector<int> v1=v;
        
        int i=0;
        int j=0;
        while(j<s.length()){
            if(set1.find(s[j])==set1.end()){
                j++;
                i=j;
                v1=v;
            }
            else if(j-i+1<n){
                v1[s[j]-'a']--;
                j++;
            }
            else if(j-i+1==n){
                
                v1[s[j]-'a']--;
                
                cout<<endl;
                j++;
                int a=1;
                for(int k=0;k<26;k++){
                    if(v1[k]!=0){
                        a=0;
                        break;
                    }
                }
                if(a==1){
                    ans.push_back(i);
                }
                v1[s[i]-'a']++;
                i++;
            }
        }
        return ans;
    }
};