class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        vector<int> v(n,-1);
        for(int i=0;i<n;i++){
            if(hours[i]>8){
                v[i]=1;
            }
        }
        vector<int> prefix(n,0);
        prefix[0]=v[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+v[i];
        }
        int maxi=0;
        int lastPosition=-1;
        for(int i=0;i<n;i++){
            if(prefix[i]>0){
                maxi=i+1;
            }
            else{
                for(int j=0;j<i;j++){
                    if(prefix[j]<prefix[i]){
                        maxi=max(maxi,i-j);
                    }
                }
                
            }
        }
        return maxi;
    }
};