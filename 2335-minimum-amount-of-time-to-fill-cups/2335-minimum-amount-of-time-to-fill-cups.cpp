class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue <int> pq;
        for(int i=0;i<amount.size();i++){
            if(amount[i]!=0){
                pq.push(amount[i]);
            }
            
        }
        int i=0;
        while(!pq.empty()){
            i++;
            int a=pq.top();
            pq.pop();
            int b;
            if(!pq.empty()){
                b=pq.top();
                pq.pop();
                b--;
                if(b>0){
                    pq.push(b);
                }
            }
            a--;
            if(a>0){
                pq.push(a);
            }   
        }
        return i;
        
    }
};