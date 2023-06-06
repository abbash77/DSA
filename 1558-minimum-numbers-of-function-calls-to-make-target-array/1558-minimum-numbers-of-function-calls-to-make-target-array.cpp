class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
             
        while(1)
        {
            int flag = 0;
            int count = 0;
           for(auto &i:nums) 
           {
               if(i>1)
               {
                   if(i%2) ans++;
                   i/=2;
                   count ++;
               }
           }
            
            if(count > 0)
            ans++;
            
            for(auto &i:nums)
            {
                if(i==1)
                {
                    i--;
                    ans++;
                }
            }
            
            for(auto &i:nums)
            {
                if(!i) flag++;
            }
            
            if(flag == nums.size()) break;
            
        }
        
        return ans;
        
    }
};