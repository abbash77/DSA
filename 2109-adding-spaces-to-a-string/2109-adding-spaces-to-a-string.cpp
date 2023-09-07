class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        vector<string> v;
        int n=s.length();
        int m=spaces.size();
        v.push_back(s.substr(0,spaces[0]));
        
        for(int i=0;i<spaces.size()-1;i++){
            v.push_back(s.substr(spaces[i],spaces[i+1]-spaces[i]));
        }
        v.push_back(s.substr(spaces[m-1],n));
        string ans="";
        for(int i=0;i<v.size()-1;i++){
            ans+=v[i]+" ";
        }
        ans+=v[v.size()-1];
        return ans;
    }
};