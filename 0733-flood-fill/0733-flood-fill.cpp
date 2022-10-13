class Solution {
public:
    void helper(vector<vector<int>>& image, int sr, int sc, int color,int colorr){
        if(sr>=image.size()||sc>=image[0].size()||sr<0||sc<0||image[sr][sc]!=colorr){
            return;
        }
        image[sr][sc]=color;
        helper(image,sr-1,sc,color,colorr);
        helper(image,sr+1,sc,color,colorr);
        helper(image,sr,sc+1,color,colorr);
        helper(image,sr,sc-1,color,colorr);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int colorr=image[sr][sc];
        if(image[sr][sc]!=color){
            helper(image,sr,sc,color,colorr);
        }
        
        return image;
         
    }
};