class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> prefix(n,0);
        vector<int> prefix1(n,0);
        prefix[0]=cardPoints[0];
        for(int i=1;i<k;i++){
            prefix[i]+=prefix[i-1]+cardPoints[i];
        }
        prefix1[n-1]=cardPoints[n-1];
        for(int i=n-2;i>n-k-1;i--){
            prefix1[i]=prefix1[i+1]+cardPoints[i];
        }
        int i=-1;
        int j=n-k;
        int maxi=INT_MIN;
        while(j<=n){
            int val=0;
            if(j==n){
                val+=prefix[i];
                maxi=max(maxi,val);
                break;
            }
            if(i==-1){
                val+=prefix1[j];
                maxi=max(maxi,val);
                j++;
                i++;
                continue;
            }
            val+=prefix[i];
            val+=prefix1[j];
            maxi=max(maxi,val);
            j++;
            i++;
        }
        return maxi;
        // return 1;    
    }
};