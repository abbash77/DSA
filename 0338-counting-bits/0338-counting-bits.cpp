class Solution {
public:
    vector<int> countBits(int n) {
        int i=0;
        vector<int> v;
        while(i<=n){
            int m=i;
            int cnt=0;
            while(m>0){
                m=m&(m-1);
                cnt++;
            }
            i++;
            v.push_back(cnt);
        }
        return v;
    }
};