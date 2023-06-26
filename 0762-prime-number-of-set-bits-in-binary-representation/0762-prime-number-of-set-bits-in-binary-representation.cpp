class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_map<int,bool> m;
        m[2]=true;
        m[3]=true;
        m[5]=true;
        m[7]=true;
        m[11]=true;
        m[13]=true;
        m[17]=true;
        m[19]=true;
        m[23]=true;
        m[29]=true;
        m[31]=true;
        int ans=0;
        for(int i=left;i<=right;i++){
            int n=i;
            int cnt=0;
            while(n>0){
                n=n&(n-1);
                cnt++;
            }
            if(m[cnt]){
                ans++;
            }
            
        }
        return ans;
    }
};