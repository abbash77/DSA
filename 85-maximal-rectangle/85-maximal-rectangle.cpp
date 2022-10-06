class Solution {
public:
    int solve(vector<int> &arr,int n){
        vector<int> leftSmall(n,-1),rightSmall(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                rightSmall[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                leftSmall[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        int area=0;
        for(int i=0;i<n;i++){
            area=max(area,(rightSmall[i]-leftSmall[i]-1)*(arr[i]));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> mat(n,vector<int>(m));
        for(int r=0;r<n;r++)
        {   for(int c=0;c<m;c++){
                mat[r][c]=matrix[r][c]-'0';
            }
        }
        for(int r=0;r<n;r++)
        {   for(int c=0;c<m;c++){
                if(r>0&&mat[r][c]!=0){
                    int curr=mat[r][c];
                    int prev=mat[r-1][c];
                    mat[r][c]=curr+prev;
                }
            }
        }
        int area=0;
        for(int i=0;i<n;i++){
            area=max(area,solve(mat[i],m));
        }
        return area;
    }
  
};