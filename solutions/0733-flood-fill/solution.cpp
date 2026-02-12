class Solution {
public:

    void solve(vector<vector<int>>& image, int x, int y, int color,int oldcolor){
        
        if(x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != oldcolor) return;

        image[x][y] = color;

        solve(image,x+1,y,color,oldcolor);
        solve(image,x-1,y,color,oldcolor);
        solve(image,x,y+1,color,oldcolor);
        solve(image,x,y-1,color,oldcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int oldcolor = image[sr][sc];

        if(oldcolor == color) return image;

        solve(image,sr,sc,color,oldcolor);
         
        return image;
    }
};
