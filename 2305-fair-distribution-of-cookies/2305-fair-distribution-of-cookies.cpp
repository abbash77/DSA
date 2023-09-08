class Solution {
public:
    int ans=INT_MAX;
    void recur(int i,vector<int> cookies,vector<int>& v,int k){
        if(i==cookies.size()){
            int maxi=INT_MIN;
            for(int l=0;l<k;l++){
                maxi=max(maxi,v[l]);
            }
            ans=min(ans,maxi);
            return ;
        }
        for(int j=0;j<k;j++){
            v[j]+=cookies[i];
            recur(i+1,cookies,v,k);
            v[j]-=cookies[i];
            if(v[j]==0){//dont understand
                break;
            }
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k,0);
        recur(0,cookies,v,k);
        return ans;
    }
};