class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue <pair<int,int>> MH;
    int m=mat.size();
    vector<int>ans;
    vector<int>v(m,0);
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            if(mat[i][j]==1)
                v[i]++;
        }
    }

    for(int i=0;i<m;i++)
    {
        if(MH.size()==k && v[i]<v[MH.top().second])
            MH.pop();
        if(MH.size()<k)
            MH.push({v[i],i});
    }
    while(!MH.empty())
    {
        ans.push_back(MH.top().second);
        MH.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};