class Solution {
public:
    int search(vector<int>& score,int val){
        int a;
        for(int i=0;i<score.size();i++){
            if(score[i]==val){
                a= i;
            }
        }
        return a;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue <int> pq;
        for(int i=0;i<score.size();i++){
            pq.push(score[i]);
        }
        vector<string> ans(score.size());
        for(int i=0;i<score.size();i++){
            int a=pq.top();
            pq.pop();
            int index=search(score,a);
            if(i==0){
                ans[index]="Gold Medal";
            }
            else if(i==1){
                ans[index]="Silver Medal";
            }
            else if(i==2){
                ans[index]="Bronze Medal";
            }
            else{
                ans[index]=to_string(i+1);
            }
            
        }
        return ans;
    }
};