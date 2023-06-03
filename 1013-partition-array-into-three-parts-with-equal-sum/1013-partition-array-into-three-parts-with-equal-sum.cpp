class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        if(sum%3!=0){
            return false;
        }
        sum=sum/3;
        int s=0;
        int part=0;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
            if(s==sum){
                part++;
                s=0;
            }
        }
        if(part>=3){
            return true;
        }
        return false;
    }
};