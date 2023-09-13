class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt=0;
        int maxSoFar=-1;
        for(int i=0;i<arr.size();i++){
            maxSoFar=max(maxSoFar,arr[i]);
            if(maxSoFar==i){
                cnt++;
            }
        }
        return cnt;
    }
};