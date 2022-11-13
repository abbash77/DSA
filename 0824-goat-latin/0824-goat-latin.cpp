class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            return true;
        }
        return false;
    }
    string func(string str){
        char z=str[0];
        for(int i=0;i<str.length();i++){
            str[i]=str[i+1];
        }
        str[str.length()-1]=z;
        return str;
    }
    string toGoatLatin(string sentence) {
        vector<string> v1;
        string str="";
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]!=' '){
                str+=sentence[i];
            }
            else{
                if(!str.empty()){
                    v1.push_back(str);
                    str.clear();
                }
            }
        }
        if(!str.empty()){
            v1.push_back(str);
        }
        string z="maa";
        for(int i=0;i<v1.size();i++){
            if(isVowel(v1[i][0])){
                
            }
            else{
                v1[i]=func(v1[i]);
            }
            v1[i]+=z;
            z+='a';
        }
        str="";
        for(int i=0;i<v1.size();i++){
            str+=v1[i];
            if(i!=v1.size()-1){
                str+=" ";
            }   
        }
        return str;
    }
};