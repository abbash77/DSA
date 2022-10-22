class Solution {
public:
    int sum(int n){
        int z=0;
        while(n>=10){
            z+=n%10;
            n=n/10;
        }
        z+=n;
        return z;
    }
    int countBalls(int lowLimit, int highLimit) {
        vector<int> ans(highLimit+1,0);
        int i=lowLimit;
        while(i<10&&i<=highLimit){
            ans[i]++;
            i++;
        }
        if(i>=10){
            while(i<=highLimit){
                int a=sum(i);
                ans[a]++;
                i++;
            }
        }
        int max=INT_MIN;
        for(int j=0;j<ans.size();j++){
            if(max<ans[j]){
                max=ans[j];
            }
        }
        return max;
    }
};