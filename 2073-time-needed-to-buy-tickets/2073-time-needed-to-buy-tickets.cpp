class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
     queue<pair<int,int>> q;
        for(int i=0;i<tickets.size();i++){
            q.push(make_pair(tickets[i],i));
        }
        int i=0;
        while(true){
            i++;
            pair<int,int> p=q.front();
            p.first--;
            q.pop();
            if(p.first!=0){
                q.push(p);
            }
            else if(p.second==k){
                break;
            }
        }
        return i;
    }
};