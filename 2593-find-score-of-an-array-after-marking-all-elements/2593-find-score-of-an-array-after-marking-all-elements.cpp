
class cmp
{
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first>b.first;
    }
};
class Solution {
public:
    long long findScore(vector<int>& nums) {
        
         priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,cmp> pq;
        vector<int> vis(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        long long ans=0;
        while(!pq.empty()){
            pair<int,int> top=pq.top();
            pq.pop();
            long long val=top.first;
            int index=top.second;
            if(vis[index]==1){
                continue;
            }
            ans+=val;
            vis[index]=1;
            if(index>0){
                vis[index-1]=1;
            }
            if(index<vis.size()-1){
                vis[index+1]=1;
            }
        }
        return ans;
    }
};