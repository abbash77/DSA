class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> ans;
        int a=-1;
        int maxi=INT_MIN;
        int i;
        int b=-1;
        int m=0;
        for(i=0;i<seats.size();i++){
            if(seats[i]==1){
                if(m==0){
                    b=i;
                    m=1;
                }
                maxi=max(maxi,i-a);
                a=i;
            }
        }
        maxi=max(maxi/2,i-a-1);
        maxi=max(maxi,b);
        return maxi;
    }
};