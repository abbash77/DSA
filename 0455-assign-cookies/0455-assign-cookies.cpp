class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int cnt=0;
        while(i<g.size()&&j<s.size()){
            if(s[j]>=g[i]){
                cnt++;
                j++;
                i++;
            }
            else if(s[j]<g[i]){
                j++;
            }
        }
        return cnt;
    }
};