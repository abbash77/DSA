class Solution {
public:
    int maximum69Number (int num) {
        vector<int> a;
        while(num>0){
            a.push_back(num%10);
            num=num/10;
        }
        reverse(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            if(a[i]==6){
                a[i]=9;
                break;
            }
        }
        int ans=0;
        for(int i=0;i<a.size();i++){
            ans+=a[i]*pow(10,a.size()-i-1);
        }
        return ans;
    }
};