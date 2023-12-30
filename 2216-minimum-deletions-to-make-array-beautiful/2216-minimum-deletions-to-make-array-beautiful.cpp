class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n= nums.size();
    int n1=n;
    int i=0, j=0;
    int cnt=0;
	
    // j is virtual index after removing ith element
    while(i<n-1 && j<n1){
        if(j%2==0 && nums[i]==nums[i+1])
        {
            n1--; // new size after deleting elements
            cnt++; //counting deleted elements
        }
        else
        {
            j++;
        }
        i++;
    }
    // if the array size after deleting is odd the removing last element to make it even
    if(n1%2!=0){
        return cnt+1;
    }
    
    return cnt;
    }
};