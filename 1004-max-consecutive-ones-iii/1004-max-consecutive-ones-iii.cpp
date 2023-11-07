class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0;
        int i=0,j=0;
        int maximum=0;
        while(j<nums.size())
        {
            if(nums[j]==0)
            {
                count++;
            }
            if(count<k)
            {
                maximum=max(j-i+1,maximum); // because we can flip 
                j++;
            }
            else if(count==k)
            {
                maximum=max(j-i+1,maximum);
                j++;
            }
            else if(count>k)
            {
                while(count>k)
                {
                    if(nums[i]==0)
                    {
                        count--;
                    }
                    i++;
                }
                j++;
            }
            
        }
        return maximum;
    }
};