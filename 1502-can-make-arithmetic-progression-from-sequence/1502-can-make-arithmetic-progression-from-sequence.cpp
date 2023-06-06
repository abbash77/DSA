class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int a=arr[0]-arr[1];
        int c=1;
   
       
        for(int i=0;i<arr.size()-1;i++){
            int diff=arr[i]-arr[i+1];
            if(diff!=a){
                c=0;
            }
        }
        return c;
    }
};