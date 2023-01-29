//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int,bool> m;
      for(int i=0;i<N;i++){
          m[arr[i]]=true;
      }
      int maxi=INT_MIN;
      for(int i=0;i<N;i++){
          if(!m[arr[i]-1]){
              int cnt=0;
              int a=m[arr[i]];
              int j=0;
              while(m[arr[i]+j]){
                  cnt++;
                  j++;
              }
              maxi=max(cnt,maxi);
          }
      }
      return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends