class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        map<int,bool> minR;
        vector<int> ans;
        for(int i=0;i<matrix.size();i++){
            int mini=INT_MAX;
            for(int j=0;j<matrix[0].size();j++){
                mini=min(mini,matrix[i][j]);
            }
            minR[mini]=true;
        }
        // map<int,int> minC;
        for(int i=0;i<matrix[0].size();i++){
            int mini=INT_MIN;
            for(int j=0;j<matrix.size();j++){
                mini=max(mini,matrix[j][i]);
            }
            if(minR.find(mini)!=minR.end()){
                ans.push_back(mini);
            }
        }
        return ans;
    }
};