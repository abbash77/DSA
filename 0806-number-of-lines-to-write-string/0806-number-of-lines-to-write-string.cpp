class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int len=1;
        int val=100;
        for(int i=0;i<s.length();i++){
            if(val-widths[s[i]-'a']>=0){
                val-=widths[s[i]-'a'];
                cout<<s[i]<<" ";
            }
            else{
                cout<<endl;
                val=100;
                val-=widths[s[i]-'a'];
                len++;
            }
        }
        vector<int> ans;
        ans.push_back(len);
        ans.push_back(100-val);
        return ans;
    }
};