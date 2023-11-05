class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end());
        int i=0;
        int j=tasks.size()-1;
        int ans=INT_MIN;
        while(j>=0){
            ans=max(ans,processorTime[i]+tasks[j]);
            i++;
            j=j-4;
        }
        return ans;
    }
};