class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="./"){
                
            }
            else if(logs[i]=="../"){
                if(!s.empty()){
                    s.pop();
                }
            }
            else{
                s.push(logs[i]);
            }
        }
        int i=0;
        while(!s.empty()){
            s.pop();
            i++;
        }
        return i;
    }
};