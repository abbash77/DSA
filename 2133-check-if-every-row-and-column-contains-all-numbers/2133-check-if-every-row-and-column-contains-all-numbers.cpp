class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        set<int> s;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                s.insert(matrix[i][j]);    
            }
            if(s.size()!=n){
                return false;
            }
            s.clear();
        }
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                s.insert(matrix[j][i]);    
            }
            if(s.size()!=n){
                return false;
            }
            s.clear();
        }
        return true;
    }
};