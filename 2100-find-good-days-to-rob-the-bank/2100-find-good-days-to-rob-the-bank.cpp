class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();//7-2=5
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        vector<int> ans;
        for(int i=1;i<n;i++){
            if(security[i-1]>=security[i]){
                prefix[i]=prefix[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(security[i+1]>=security[i]){
                suffix[i]=suffix[i+1]+1;
            }
        }
        for(int i=0;i<n;i++){
            if(prefix[i]-1>=time&&suffix[i]-1>=time){
                ans.push_back(i);
            }
        }
        return ans;        
        
        
    }
};