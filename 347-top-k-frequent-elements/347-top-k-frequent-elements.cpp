class Solution {
public:
    int search(map<int,int>& m,int n){
        int a;
        for(auto i:m){
            if(i.second==n){
                m[i.first]=-1;
                a=i.first;
                break;
            }
        }
        return a;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int z=k;
        if(nums.size()==1){
            return nums;
        }
        vector<int> res;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=0;
        }
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> a;
        for(auto i:m){
            a.push_back(i.second);
        }
        sort(a.begin(),a.end(),greater<int>());
        int x;
        for(int i=0;i<k;i++){
            x=search(m,a[i]);
            res.push_back(x);
        }
        return res;
        
        
    }
};