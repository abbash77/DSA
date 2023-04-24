class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum=0;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            sum+=nums[i];
        }
        double curr=sum;
        int cnt=0;
        while(curr>sum/2&&!pq.empty()){
            double a=pq.top();
            pq.pop();
            double b=a/2;
            curr-=b;
            pq.push(b);
            cnt++;
        }
        return cnt;
    }
};