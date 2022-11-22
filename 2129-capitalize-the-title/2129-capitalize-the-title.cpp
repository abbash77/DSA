class Solution {
public:
    string capitalizeTitle(string title) {
        vector<string> v;
        string str="";
        int a;
        for(int i=0;i<title.length();i++){
            if(title[i]!=' '){
                str=str+title[i];
            }
            else{
                    v.push_back(str);
                    str.clear();
                
            }
            
        }
        v.push_back(str);
        str="";
        for(int i=0;i<v.size();i++){
            if(v[i].length()>2){
                for(int j=0;j<v[i].length();j++){
                    if(j==0){
                        if(v[i][j]>=97&&v[i][j]<=122){
                            v[i][j]=v[i][j]-32;
                        }
                    }
                    else{
                        if(v[i][j]>=65&&v[i][j]<=90){
                            v[i][j]=v[i][j]+32;
                        }
                    }
                    
                }
            }
            else{
                for(int j=0;j<v[i].length();j++){
                        if(v[i][j]>=65&&v[i][j]<91){
                            v[i][j]=v[i][j]+32;
                        }
                    
                }
            }
        }

        
        for(int i=0;i<v.size();i++){
            str+=v[i];
            if(i!=v.size()-1){
                str+=" ";
            }
            
        }
        return str;
    }
};