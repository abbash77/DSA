class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s1;
        for(int i=0;i<paths.size();i++){
            s1.insert(paths[i][0]);
        }
        for(int i=0;i<paths.size();i++){
            if(s1.find(paths[i][1])==s1.end()){
                return paths[i][1];
            }
        }
        return "";
    }
};