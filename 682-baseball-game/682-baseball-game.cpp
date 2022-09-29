class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                if(!s.empty()){
                    s.pop();   
                }
            }
            else if(operations[i]=="D"){
                if(!s.empty()){
                    s.push(s.top()*2);
                }  
            }
            else if(operations[i]=="+"){
                if(!s.empty()){
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    int c=a+b;
                    s.push(b);
                    s.push(a);
                    s.push(c);
                }
                
            }
            else{
                s.push(stoi(operations[i]));
            }
        }
        int sum=0;
        while(!s.empty()){
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
};