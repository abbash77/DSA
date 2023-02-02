//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int index(int arr[],int val,int s,int e){
        int mid=(s+e)/2;
        int ans=-1;
        while(s<=e){
            if(arr[mid]>val){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	 sort(arr,arr+n);
        sort(dep,dep+n);
    	int ans=INT_MIN;
    	for(int i=0;i<n-1;i++){
    	    int j=index(arr,dep[i],i+1,n-1);
    	    if(j!=-1){
    	        ans=max(ans,j-i);
    	    }
    	   // j-i
    	}
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends