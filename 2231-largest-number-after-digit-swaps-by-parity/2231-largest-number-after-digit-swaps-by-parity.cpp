class Solution {
public:
    int largestInteger(int num) {
        priority_queue <int, vector<int>, greater<int> > even;
        priority_queue <int, vector<int>, greater<int> > odd;
        int temp=num;
        while(temp>0){
            int rem=temp%10;
            if(rem%2==0){
                even.push(rem);
            }
            else{
                odd.push(rem);
            }
            temp=temp/10;
        }
        int temp2=num;
        int sum=0;
        int i=0;
        while(temp2>0){
            int rem2=temp2%10;
            if(rem2%2==0){
                sum+=even.top()*pow(10,i);
                even.pop();
            }
            else{
                sum+=odd.top()*pow(10,i);
                odd.pop();
            }
            temp2=temp2/10;
            i++;
        }
        return sum;
    }
};