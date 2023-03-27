class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        v.push_back(1);
        long long ans=1;
        int i=rowIndex;
        int j=1;
        while(i>0){
            ans=(ans*i)/j;
            v.push_back(ans);
            i--;
            j++;
        }
        return v;
    }
};