//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int win_size=0;
        
        for(int i=0;i<n;i++){
            if(arr[i] <=k)
                win_size++;
        }
        int non_fav=0;
        for(int i=0;i<win_size;i++){
            if(arr[i]>k){
                non_fav++;
            }
        }
        int mini=non_fav;
        for(int i=1;i<=n-win_size;i++){
            if(arr[i+win_size-1]>k){
                non_fav++;
            } 
            if(arr[i-1]>k){
                non_fav--;
            }
            mini=min(mini,non_fav);
        }
        return mini;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends