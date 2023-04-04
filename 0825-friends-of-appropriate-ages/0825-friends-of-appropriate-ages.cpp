class Solution {
public:
    bool isPossible(int val,int num){
        if(num*0.5+7>=val){
            return false;
        }
        if(num<100&&val>100){
            return false;
        }
        return true;
    }
    int bn(int val,int s,int e,vector<int>& ages){
        int ans=-1;
        int mid=(s+e)/2;
        while(s<=e){
            if(isPossible(val,ages[mid])){
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
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int i=0;
        int j=1;
        int ans=0;
        for(int i=0;i<ages.size();i++){
            int val=bn(ages[i],i+1,ages.size()-1,ages);
            int index=upper_bound(ages.begin(),ages.end(),ages[i])-ages.begin()-1;
            if(val!=-1){
                if(index==val){
                    if(ages[val]==ages[i]){
                        ans+=val-i;
                    }
                    ans+=val-i;
                }
                else{
                    ans+=index-i;
                    ans+=val-i;
                }
                
            }
        }
        return ans;
    }
};