class Solution {
public:
    vector<int> next(vector<int>& v){
        stack<int> s;
        s.push(-1);
        int n=v.size();
        vector<int> v1(n);
        for(int i=n-1;i>=0;i--){
            int curr=v[i];
            while(s.top()!=-1&&v[s.top()]>=curr){
                s.pop();
            }
            v1[i]=s.top();
            s.push(i);
        }
        return v1;
    }
    vector<int> prev(vector<int>& v){
        stack<int> s;
        s.push(-1);
        int n=v.size();
        vector<int> v1(n);
        for(int i=0;i<n;i++){
            int curr=v[i];
            while(s.top()!=-1&&v[s.top()]>=curr){
                s.pop();
            }
            v1[i]=s.top();
            s.push(i);  
        }
        return v1;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nexti(n);
        nexti=next(heights);
        vector<int> previ(n);
        previ=prev(heights);
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int l=heights[i];
            if(nexti[i]==-1){
                nexti[i]=n;
            }
            int b=nexti[i]-previ[i]-1;
            int area=l*b;
            maxi=max(maxi,area);
        }
        return maxi;
    }
};