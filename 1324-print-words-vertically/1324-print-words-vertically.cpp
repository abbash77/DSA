class Solution {
public:
    vector<string> printVertically(string s) {
    vector<vector<char>> v;
         vector<char> v1;
        vector<string> v2;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                v1.push_back(s[i]);
            }
            else{
                v.push_back(v1);
                v1.clear();
            }
        }
        if(!v1.empty()){
             v.push_back(v1);
        }
        int maxi=0;
        for(int i=0;i<v.size();i++){
            if(maxi<v[i].size()){
                maxi=v[i].size();
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i].size()<maxi){
                int diff=maxi-v[i].size();
                for(int j=0;j<diff;j++){
                    v[i].push_back(' ');
                }
            }
        }
        int row=v.size();
        int col=v[0].size();
        for(int i=0;i<col;i++){
            string s="";
            for(int j=0;j<row;j++){
                s+=v[j][i];
            }
                string z="";
                int c=0;
                for(int k=0;k<s.length();k++){
                    if(s[k]==' '){
                        c++;
                    }
                    else{
                        for(int m=0;m<c;m++){
                            z+=' ';
                        }
                        z+=s[k];
                        c=0;
                    }
                }
                v2.push_back(z);
        }
        return v2;
    }
};