class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int,set<int>> m;
        m[0].insert(0);
        int x=0;
        int y=0;
        for(int i=0;i<path.length();i++){
            if(path[i]=='N'){
                y++;
            }
            else if(path[i]=='S'){
                y--;
            }
            else if(path[i]=='E'){
                x++;
            }
            else if(path[i]=='W'){
                x--;
            }
            if(m.find(x)!=m.end()){
                if(m[x].find(y)!=m[x].end()){
                    return true;
                }
            }
            m[x].insert(y);
        }
        return false;
    }
};