class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<string,int> m;
        int j=0;
        
        long long r=n;
        string main="";
         while(r>0){
                int a=r%10;
                main+=a+'0';
                r=r/10;
        }
         reverse(main.begin(),main.end());
        string s="";
        while(s.length()<=main.length()){
            s="";
            long long l=pow(2,j);
            while(l>0){
                long long a=l%10;
                s+=a+'0';
                l=l/10;
            }
            reverse(s.begin(),s.end());
            m[s]=s.length();
            j++;
        }
        vector<string> v;
        for(auto i:m){
            if(i.second==main.length()){
                v.push_back(i.first);
            }
        }
        unordered_map<char,int> m1;
        for(int i=0;i<main.length();i++){
            m1[main[i]]++;
        }
        
        unordered_map<char,int> m2=m1;
        for(int i=0;i<v.size();i++){
            int p=0;
            for(int j=0;j<v[i].size();j++){
                m2[v[i][j]]--;
                if(m2[v[i][j]]==0){
                    p++;
                }
            }
            if(p==m2.size()){
                return true;
            }
            m2=m1;
            
        }
        return false;
    }
};