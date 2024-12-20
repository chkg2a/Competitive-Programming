/* 733. Floor Fill
You are given an image represented by an m x n grid of integers image, where
image[i][j] represents the pixel value of the image. You are also given three
integers sr, sc, and color. Your task is to perform a flood fill on the image
starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that
share a side with the original pixel, either horizontally or vertically) and
shares the same color as the starting pixel. Keep repeating this process by
checking neighboring pixels of the updated pixels and modifying their color if
it matches the original color of the starting pixel. The process stops when
there are no more adjacent pixels of the original color to update. Return the
modified image after performing the flood fill.



Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:



From the center of the image with position (sr, sc) = (1, 1) (i.e., the red
pixel), all pixels connected by a path of the same color as the starting pixel
(i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not horizontally or
vertically connected to the starting pixel.

 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        dfs(sr,sc,ans,image,color,delrow,delcol,inicolor);
        return ans;

    }

    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int color, int delrow[], int delcol[], int inicolor){

        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();

        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol>=0 && ncol<m &&  image[nrow][ncol] == inicolor && ans[nrow][ncol] != color){
                dfs(nrow,ncol,ans,image,color,delrow,delcol,inicolor);
            }
        }
        

    }
};

int main() {
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  int sr = 1, sc = 1, color = 2;
  Solution sol;
  for(vector<int> i : sol.floodFill(image, sr, sc, color)){
    for(int x : i){
      cout << x << ' ';
    }
    cout << endl;
  }


  return 0;
}
