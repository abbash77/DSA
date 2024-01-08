class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0;
        int j=0;
        int sum=0;
        int cnt=0;
        while(j<arr.size()){
            if(j-i<k-1){
                sum+=arr[j];
                j++;
            }
            else if(j-i==k-1){
                sum+=arr[j];
                int val=sum/k;
                if(val>=threshold){
                    cnt++;
                }
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return cnt;
    }
};