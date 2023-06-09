class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        int maxi=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[0]>=1&&i==0){
                arr[0]=1;
                continue;
            }
            if(abs(arr[i]-arr[i-1])>1){
                if(arr[i]>=arr[i-1]+1){
                    arr[i]=arr[i-1]+1;
                    maxi=max(maxi,arr[i]);
                }
            }
            else if(arr[i]-arr[i-1]==1){
                maxi=max(maxi,arr[i]);
            }
        }
        return maxi;
    }
};