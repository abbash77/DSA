//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int j=0;
        int mini=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>x){
                mini=min(mini,i-j+1);
                
                while(j<i){
                    sum-=arr[j];
                    j++;
                    if(sum>x){
                        mini=min(mini,i-j+1);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        if(mini==INT_MAX){
            return 0;
        }
        return mini;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends