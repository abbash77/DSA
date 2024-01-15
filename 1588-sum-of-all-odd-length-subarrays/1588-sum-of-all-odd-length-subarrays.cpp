class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        // 1 5 7 12 15
        int n=arr.size();
        vector<int> prefix(n,0);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j=j+2){
                if(i-1>=0){
                    sum+=prefix[j]-prefix[i-1];
                }
                else{
                    sum+=prefix[j];
                }
                
            }
        }
        return sum;
    }
};