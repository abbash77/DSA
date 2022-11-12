class Solution {
public:
    vector<vector<int>> finalans;
    void help(int n, int k,int index,vector<int> &ans){
        if(ans.size()==k){
            finalans.push_back(ans);
            return;
        }
        for(int j=index;j<=n;j++){
            ans.push_back(j);
            help(n,k,j+1,ans);
            ans.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        help(n,k,1,ans);
        return finalans;
    }
};