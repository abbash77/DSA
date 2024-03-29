//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int s=0;
        int e=N-1;
        int minCost=0;
        int maxCost=0;
        int st=0;
        int et=N-1;
        while(s<=e){
            minCost+=candies[s];
            e=e-K;
            s++;
            
        }
        while(st<=et){
            maxCost+=candies[et];
            st=st+K;
            et--;
        }
        vector<int> ans{minCost,maxCost};
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends