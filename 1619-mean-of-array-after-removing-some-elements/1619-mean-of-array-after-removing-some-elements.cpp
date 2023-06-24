class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        
        int s = n*5/100;
        
        double sum = 0;
        for(int i=s;i<arr.size()-s;i++)
            sum+=arr[i];
        
        return sum/(double)(n-s-s);
    }
};