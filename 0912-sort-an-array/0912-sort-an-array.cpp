class Solution {
public:
    void heapify(vector<int> &arr,int i,int n){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n&&arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n&&arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,largest,n);
        }
    }
    void sort(vector<int> &arr,int n){
        while(n>1){
            swap(arr[n-1],arr[0]);
            n--;
            heapify(arr,0,n);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,i,n);
        }
        sort(nums,n);
        return nums;
    }
    
};