class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                long a=s.top();
                s.pop();
                long b=s.top();
                long c;
                s.pop();
                if(tokens[i]=="+"){
                    c=b+a;
                }
                else if(tokens[i]=="*"){
                    c=a*b;
                }
                else if(tokens[i]=="/"){
                    c=b/a;
                }
                else if(tokens[i]=="-"){
                    c=b-a;
                }
                s.push(c);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};