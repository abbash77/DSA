class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int> > pq;
        int a=0;
        while(extraStudents>0){
            if(a==0){
                for(int i=0;i<classes.size();i++){
                double a=double(classes[i][0]+1)/double(classes[i][1]+1)-double(classes[i][0])/double(classes[i][1]);
                pq.push({a,i});
            }
                a=1;
            }
            
            pair<double,int> p=pq.top();
            pq.pop();
            classes[p.second][0]++;
            classes[p.second][1]++;
            double b=double(classes[p.second][0]+1)/double(classes[p.second][1]+1)-double(classes[p.second][0])/double(classes[p.second][1]);
            pq.push({b,p.second});
            extraStudents--;
        }
        double cnt=0;
        for(int i=0;i<classes.size();i++){
            double a=double(classes[i][0])/double(classes[i][1]);
            cnt+=a;
        }
     double ans=(double)cnt/(double)classes.size();
        return ans;
    }
};