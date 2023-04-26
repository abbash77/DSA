class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
         priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        
        for(int i=0;i<values.size();i++){
            pq.push({values[i],labels[i]});
        }
        
        int sum=0;
        while(!pq.empty()){
            if(numWanted<=0)
                break;
            auto mx=pq.top();
            pq.pop();
            if(mp[mx.second]<useLimit){
                sum+=mx.first;
                mp[mx.second]++;
                numWanted--;
            }
        }
        return sum;
    }
};