class Solution {
public:
    vector<string> ans;
    void recur(string st,unordered_map<char,string> m,string digits,int i){
        if(i==digits.length()){
            if(st.length()>0){
                            ans.push_back(st);

            }
            return ;
        }
        for(int j=0;j<m[digits[i]].length();j++){
            st+=m[digits[i]][j];
            recur(st,m,digits,i+1);
            st.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> m;
        m['2']="abc";
         m['3']="def";
         m['4']="ghi";
         m['5']="jkl";
         m['6']="mno";
         m['7']="pqrs";
         m['8']="tuv";
         m['9']="wxyz";
        recur("",m,digits,0);
        return ans;
        
        
    }
};