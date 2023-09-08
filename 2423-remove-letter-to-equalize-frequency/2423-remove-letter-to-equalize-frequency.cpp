class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int> m;
        vector<int> v;
        for(int i=0;i<word.length();i++){
            m[word[i]]++;
        }
        if(m.size()==1){
            return true;
        }
        for(auto i:m){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        if(v[0]==v[v.size()-2]&&abs(v[0]-v[v.size()-1])==1){
            return true;
        }
        else if(v[0]==v[v.size()-1]&&v[0]==1){
            return true;
        }
        else if(v[1]==v[v.size()-1]&&v[0]==1){
            return true;
        }
        return false;

        
        
        
    }
};