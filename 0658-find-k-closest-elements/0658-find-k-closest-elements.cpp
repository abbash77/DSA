class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue <int> maxheap;
        priority_queue <int, vector<int>, greater<int> > minheap;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
           if(arr[i]<=x){
               maxheap.push(arr[i]);
           }
            else{
                minheap.push(arr[i]);
            }
        }
        for(int i=0;i<k;i++){
            int a=-1010101;
            int b=-1010101;
            if(!maxheap.empty()){
                a=maxheap.top();
            }
            if(!minheap.empty()){
                b=minheap.top();
            }
            if(a==-1010101&&b!=-1010101){
                minheap.pop();
                ans.push_back(b);
            }
            else if(a!=-1010101&&b==-1010101){
                maxheap.pop();
                ans.push_back(a);
            }
            if(a!=-1010101&&b!=-1010101&&abs(a-x)>abs(b-x)){
                minheap.pop();
                ans.push_back(b);
            }
            else if(a!=-1010101&&b!=-1010101&&abs(a-x)<=abs(b-x)){
                maxheap.pop();
                ans.push_back(a);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};