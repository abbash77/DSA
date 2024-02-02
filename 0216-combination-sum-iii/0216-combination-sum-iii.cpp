class Solution {
public:
    vector<vector<int>> ans;
    void recur(int i,int k,int n,vector<int> &v){
        if(k==0&&n==0){
            ans.push_back(v);
            return;
        }
        if(i>9){
            return;
        }
        
        recur(i+1,k,n,v);
        v.push_back(i);
        recur(i+1,k-1,n-i,v);
        v.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        recur(1,k,n,v);
        return ans;
    }
};