class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
        priority_queue<int> pq;
        for(int i=0;i<piles.size();i++){
            sum+=piles[i];
            pq.push(piles[i]);
        }
        while(k>0){
            int t=pq.top();
            int top=pq.top()/2;
            pq.pop();
            pq.push(t-top);
            sum-=top;
            k--;
        }
        return sum;
    }
};