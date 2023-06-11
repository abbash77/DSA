class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int med=(n-1)/2;
        int i=0;
        int j=n-1;
        vector<int> v;
        while(i<=j){
            if(abs(arr[j]-arr[med])>=abs(arr[i]-arr[med])){
                v.push_back(arr[j]);
                if(v.size()==k){
                    break;
                }
                j--;
            }
            else{
                v.push_back(arr[i]);
                if(v.size()==k){
                    break;
                }
                i++;
            }
        }
        return v;
    }
};