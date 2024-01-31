class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();//7-2=5
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        vector<int> ans;
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                prefix[i]=prefix[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i+1]<arr[i]){
                suffix[i]=suffix[i+1]+1;
            }
        }
        int maxi=0;
        for(int i=1;i<n-1;i++){
            if(suffix[i]>1&&prefix[i]>1){
                maxi=max(maxi,suffix[i]+prefix[i]-1);
            }
            
        }
        if(maxi<=2){
            return 0;
        }
        return maxi;  
    }
};