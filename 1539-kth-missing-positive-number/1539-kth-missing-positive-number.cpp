class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int,int> m;
        vector<int> v;
        int b;
        int n=arr[arr.size()-1]+k;
        for(int i=1;i<=n;i++){
            m[i]=0;
        }
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(auto i:m){
            if(i.second==0){
                b=i.first;
                 v.push_back(b);
            }
           
        }
       
        return v[k-1];
    }
};