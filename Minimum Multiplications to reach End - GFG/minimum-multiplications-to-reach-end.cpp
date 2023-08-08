//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        vector<int> dist(99999,INT_MAX);
        dist[start]=0;
        q.push({0,start});
        while(!q.empty()){
            int itr=q.front().first;
            int num=q.front().second;
            q.pop();
            
            for(int i=0;i<arr.size();i++){
                if(itr+1<dist[(arr[i]*num)%100000]){
                    dist[(arr[i]*num)%100000]=itr+1;
                    q.push({itr+1,(arr[i]*num)%100000});
                }
                
            }
        }
        if(dist[end]==INT_MAX){
            return -1;
        }
        return dist[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends