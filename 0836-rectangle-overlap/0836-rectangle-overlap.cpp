class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int ax1=rec1[0];
        int ax2=rec1[2];
        int ay1=rec1[1];
        int ay2=rec1[3];
        int bx1=rec2[0];
        int bx2=rec2[2];
        int by1=rec2[1];
        int by2=rec2[3];
        
        if(ax2<=bx1 || ax1>=bx2 || ay1>=by2 || ay2<=by1){
              return false;
         }
        return true;
    }
};