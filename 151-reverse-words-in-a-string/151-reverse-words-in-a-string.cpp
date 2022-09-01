class Solution {
public:
    string reverseWords(string s) {
        vector<string> v1;
        string str="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                str+=s[i];
            }
            else{
                if(!str.empty()){
                    v1.push_back(str);
                    str="";
                }
            }
        }
        if(!str.empty()){
            v1.push_back(str);
        }
        int m=0;
        int e=v1.size()-1;
        while(m<e){
            swap(v1[m],v1[e]);
            m++;
            e--;
        }
        string s1="";
        for(int i=0;i<v1.size();i++){
            if(i==0){
                s1+=v1[0];
            }
            else{
                s1+=" ";
                s1+=v1[i];
            }
            
        }
        return s1;
    }
};