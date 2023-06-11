class Solution {
public:
    bool isPossible(int mid,vector<int> position,int m){
        m--;
        int k=0;
        for(int i=1;i<position.size();i++){
            if(position[i]-position[k]>=mid){
                m--;
                k=i;
            }
        }
        if(m<=0){
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s=0;
        int e=position[position.size()-1]-position[0];
        int mid=(s+e)/2;
        int ans=-1;
        while(s<=e){
            if(isPossible(mid,position,m)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
};