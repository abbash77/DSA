class Solution {
public:
    bool isPossible(long long val,int index, int n, int m){
        long long left = index+1,leftsum = 0;
        long long right = n-index-1,rightsum = 0;
        if(left<val) leftsum = left*val - left*(left-1)/2;
        else leftsum = val*(val+1)/2 + (left-val);
        if(right<val) rightsum = right*val - right*(right+1)/2;
        else rightsum = val*(val-1)/2 + (right-val+1);
        return (leftsum+rightsum) <= m;
    }
    int maxValue(int n, int index, int maxSum) {
        int s=1;
        int e=maxSum;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(mid,index,n,maxSum)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            
        }
        return ans;
    }
};