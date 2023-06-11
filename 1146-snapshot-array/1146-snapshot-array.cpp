class SnapshotArray {
public:
    vector<vector<pair<int,int>>>snapshot;
int s;
    SnapshotArray(int length) {
      snapshot.resize(length,vector<pair<int, int>>(1, {0, 0}));
      s=0;  
    }
    
    void set(int index, int val) {
        snapshot[index].push_back({s,val});
    }
    
    int snap() {
        s++;
        return s-1;
    }
    
    int get(int index, int snap_id) {
        int l=0,h=snapshot[index].size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(snapshot[index][mid].first<=snap_id)l=mid+1;
            else h=mid-1;
        }
        return snapshot[index][h].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */