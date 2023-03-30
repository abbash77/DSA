class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int r=m-1;
        double ans=1;
        int i=1;
        while(i<=r){
            ans=ans*(N-r+i)/i;
            i++;
        }
        return (int)ans;
    }
};