class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        set<int> se;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                while(!st.empty()&&st.top().first!='('){
                    st.pop();
                }
                if(st.empty()){
                    se.insert(i);
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push({s[i],i});   
            }
        }
        while(!st.empty()){
            pair<char,int> p=st.top();
            st.pop();
            if(p.first=='('||p.first==')'){
                se.insert(p.second);
            }
            
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(se.find(i)==se.end()){
                ans+=s[i];
            }
        }
        return ans;
        
    }
};