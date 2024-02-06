class NumArray {
public:
    vector<int> seg;
    int size;
    
    NumArray(vector<int>& nums) {
        int n=nums.size();
        size=n;
        
        seg.resize(4*n);
        build(0,0,n-1,nums);
    }
    void build(int idx,int low,int high,vector<int> &arr){
        if(low==high){
            seg[idx]=arr[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    int rangeQuery(int idx,int low,int high,int l,int r){
        if(r<low||l>high){
            return 0;
        }
        if(high<=r&&low>=l){
            return seg[idx];
        }
        int mid=low+(high-low)/2;
        int left=rangeQuery(2*idx+1,low,mid,l,r);
        int right=rangeQuery(2*idx+2,mid+1,high,l,r);
        return left+right;
    }
    void updateUtil(int idx,int low,int high,int i,int val){
        if(low==high){
            seg[idx]=val;
            return;
        }
        int mid=low+(high-low)/2;
        if(i<=mid){
            updateUtil(2*idx+1,low,mid,i,val);
        }
        else{
            updateUtil(2*idx+2,mid+1,high,i,val);
        }
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    
    
    void update(int index, int val) {
        updateUtil(0,0,size-1,index,val);
        
    }
    
    int sumRange(int left, int right) {
        return rangeQuery(0,0,size-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */