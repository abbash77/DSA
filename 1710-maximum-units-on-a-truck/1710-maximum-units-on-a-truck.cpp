class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        if(boxTypes.size()>1){
            sort(boxTypes.begin(),boxTypes.end(),cmp);
        }
        
        int i=0;
        int ans=0;
        while(truckSize>0){
            if(boxTypes[i][0]<=truckSize){
                ans+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else{
                ans+=boxTypes[i][1]*truckSize;
                break;
            }
            i++;
            if(i==boxTypes.size()){
                break;
            }
        }
        return ans;
    }
};