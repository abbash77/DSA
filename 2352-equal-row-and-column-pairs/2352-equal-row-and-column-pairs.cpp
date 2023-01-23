class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                m[i].push_back(grid[j][i]);
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(m[i]==grid[j]){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};