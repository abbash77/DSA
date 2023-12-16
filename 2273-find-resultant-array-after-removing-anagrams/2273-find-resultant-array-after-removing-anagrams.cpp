class Solution {
public:
    bool isAna(string s1,string s2){
        vector<int> v(26,0);
        int n1=s1.length();
        int n2=s2.length();
        if(n1!=n2){
            return false;
        }
        for(int i=0;i<n1;i++){
            v[s1[i]-'a']+=1;
            v[s2[i]-'a']-=1;
        }
        for(int i=0;i<26;i++){
            if(v[i]!=0){
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(!isAna(words[i-1],words[i])){
                ans.push_back(words[i]);
            }
            
        }
        
        return ans;
        
    }
};