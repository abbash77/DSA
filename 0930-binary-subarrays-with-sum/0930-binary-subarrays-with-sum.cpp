class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0;
        int sum=0;
        int n=nums.size();
        vector<int> d(n+1,1);
        int v=1;
        for(int j=n-1;j>=0;j--){
            if(nums[j]==0){
                v++;
                d[j]=v;
            }
            else{
                v=1;
            }
        }
        int ans=0;
        int m=0;
        for(int j=0;j<nums.size();j++){
            if(m==1){
                sum=0;
                i=j;
                m=0;
            }
            sum+=nums[j];
            if(sum>goal){
                
                m=1;
                
            }
            else if(sum==goal){
                ans+=d[j+1];
                int a=0;
                while(i<=j){
                    if(nums[i]==1){
                        i++;
                        sum--;
                        if(a!=0){
                            ans+=d[j+1];
                        }
                        a++;
                        
                        break;
                    }
                    if(a!=0){
                        ans+=d[j+1];
                        
                    }
                    a++;
                    i++;

                }
            }
        }
        return ans;
    }
};