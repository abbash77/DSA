class Solution {
public:
    bool isPalin(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void helper(string s,int index, vector<vector<string>> &res,vector<string>& v){
        if(index==s.size()){
            res.push_back(v);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalin(s,index,i)){
                v.push_back(s.substr(index,i-index+1));
                helper(s,i+1,res,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
         vector<vector<string>> res;
        vector<string> v1;
        helper(s,0,res,v1);
        return res;
    }
};