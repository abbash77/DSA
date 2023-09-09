class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> hs;
        string result="",temp="";
        
        for(int i=0;i<dictionary.size(); i++){
            hs.insert(dictionary[i]);
        }
        
        for(int i=0; i<sentence.size(); i++){            
            result.push_back(sentence[i]);
            temp.push_back(sentence[i]);             
            if(hs.find(temp)!=hs.end()){
                temp="";
                while(sentence[i]!=' '&& i<sentence.size()){
                    i++;
                    if(sentence[i]==' ')
                        result.push_back(' ');
                }
            }
            if(sentence[i]==' '){
                temp="";
            }
        }
        return result;
    }
};