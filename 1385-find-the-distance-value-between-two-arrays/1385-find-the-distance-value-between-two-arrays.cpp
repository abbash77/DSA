class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int cnt=0;
        for(int i=0;i<arr1.size();i++){
            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])>d){
                    if(arr2[j]-arr1[i]>0){
                        cnt++;
                        break;
                    }
                    if(j==arr2.size()-1){
                        cnt++;
                    }
                }
                else{
                    break;
                }
            }
        }
        return cnt;
    }
};