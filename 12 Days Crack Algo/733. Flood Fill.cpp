class Solution {
public:
    void paint(vector<vector<int>>& image, int sr, int sc, int starting,int color){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
        if(image[sr][sc] != starting || image[sr][sc] == color) return;
        image[sr][sc] = color;
        //optimisation of dfs, recursive call only when necessary
        if(sr +1 < image.size())paint(image,sr + 1,sc,starting,color);
        if(sr >= 1)paint(image,sr - 1,sc,starting,color);
        if(sc + 1< image[0].size())paint(image,sr,sc + 1,starting,color);
        if(sc>=1)paint(image,sr,sc-1,starting,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int starting = image[sr][sc];
        if(starting == color) return image;
        paint(image,sr,sc,image[sr][sc],color);
        return image;
    }
};
