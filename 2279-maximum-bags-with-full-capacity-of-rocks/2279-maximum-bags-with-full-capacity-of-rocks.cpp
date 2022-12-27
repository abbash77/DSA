class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i=0;i<capacity.size();i++){
             capacity[i]=capacity[i]-rocks[i];
        }
        priority_queue <int, vector<int>, greater<int> > pq;
        int cnt=0;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]!=0){
                pq.push(capacity[i]);
            }
            else{
                cnt++;
            }
        }
        while(true){ 
            if(!pq.empty()){
                int a;
                a=pq.top();
                pq.pop();
                if(additionalRocks-a>=0){
                    additionalRocks=additionalRocks-a;
                    cnt++;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        return cnt;
        
    }
};