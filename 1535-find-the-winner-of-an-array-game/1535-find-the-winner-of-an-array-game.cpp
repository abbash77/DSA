class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int a=arr[0];
        int b=arr[1];
        queue<int> q;
        int cnt=0;
        int winner=-1;
        for(int i=2;i<arr.size();i++){
            q.push(arr[i]);
        }
        while(true){
            if(a>b){
                q.push(b);
                b=q.front();
                q.pop();
                if(winner==a){
                    cnt++;
                }
                else{
                    cnt=1;
                    winner=a;
                }
                
            }
            else{
                a=b;
                q.push(a);
                b=q.front();
                q.pop();
                if(winner==a){
                    cnt++;
                }
                else{
                    cnt=1;
                    winner=a;
                }
            }
            if(cnt>=k||cnt>=arr.size()){
                break;
            }
        }
        return winner;
    }
};