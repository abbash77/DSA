class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> m;
        set<int> s;
        for(int i=0;i<adjacentPairs.size();i++){
            int u=adjacentPairs[i][0];
            int v=adjacentPairs[i][1];
            m[u].push_back(v);
            m[v].push_back(u);
        }
        int startPoint;
        for(auto i:m){
            if(i.second.size()==1){
                startPoint=i.first;
                break;
            }
        }
        vector<int> ans;
        
        while(true){
            ans.push_back(startPoint);
            s.insert(startPoint);
            if(m[startPoint].size()==1){
                if(s.find(m[startPoint][0])==s.end()){
                    startPoint=m[startPoint][0];
                }
                else{
                    break;
                }
                
            }
            else{
                
                if(s.find(m[startPoint][0])==s.end()){
                    startPoint=m[startPoint][0];
                }
                else if(s.find(m[startPoint][1])==s.end()){
                    startPoint=m[startPoint][1];
                }
                else{
                    break;
                }
            }
            
        }
        return ans;
    }
};