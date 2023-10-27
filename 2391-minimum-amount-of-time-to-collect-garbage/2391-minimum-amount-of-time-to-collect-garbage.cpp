class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char,int> m;
        int ans=0;
        for(int i=garbage.size()-1;i>=0;i--){
            for(int j=0;j<garbage[i].size();j++){
                if(m.find('G')==m.end()&&garbage[i][j]=='G'){
                    m['G']=i;
                }
                else if(m.find('M')==m.end()&&garbage[i][j]=='M'){
                    m['M']=i;
                }
                else if(m.find('P')==m.end()&&garbage[i][j]=='P'){
                    m['P']=i;
                }
            }
            if(m.size()==3){
                break;
            }
        }
        vector<pair<string,unordered_map<char,int>>> v;
        for(int i=0;i<garbage.size();i++){
            unordered_map<char,int> temp;
            for(int j=0;j<garbage[i].size();j++){
                temp[garbage[i][j]]++;
            }
            v.push_back({garbage[i],temp});
        }
        if(m.find('G')!=m.end()){
            int idx=m['G'];
            
            for(int i=0;i<=idx;i++){
                ans+=v[i].second['G'];
                if(i!=idx){
                    ans+=travel[i];
                }
            }
        }
       
        
        if(m.find('M')!=m.end()){
            int idx=m['M'];
            
            for(int i=0;i<=idx;i++){
                ans+=v[i].second['M'];
                if(i!=idx){
                    ans+=travel[i];
                }
            }
        }
        if(m.find('P')!=m.end()){
            int idx=m['P'];
           
            for(int i=0;i<=idx;i++){
                ans+=v[i].second['P'];
                if(i!=idx){
                    ans+=travel[i];
                }
            }
        }
        return ans;
    }
};