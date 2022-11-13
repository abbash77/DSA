class Solution {
public:
    string reverseWords(string s) {
        string str="";
        vector<string> v1;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                str+=s[i];
            }
            else if(s[i]==' '){
                if(!str.empty()){
                    v1.push_back(str);
                    str.clear();
                }
            }
        }
        if(!str.empty()){
            v1.push_back(str);
        }
        reverse(v1.begin(),v1.end());
        string ans="";
        for(int i=0;i<v1.size();i++){
            ans+=v1[i];
            if(i!=v1.size()-1){
                ans+=' ';
            }
            
        }
        return ans;
    }
    
};