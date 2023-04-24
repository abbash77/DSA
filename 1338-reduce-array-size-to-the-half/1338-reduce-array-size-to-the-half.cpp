class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        priority_queue<int> pq;
        for(auto i:m){
            pq.push(i.second);
        }
        int n=arr.size();
        int h=n;
        int ans=0;
        while(h>n/2){
            int a=pq.top();
            pq.pop();
            h-=a;
            ans++;
        }
        return ans;
    }
};