/************************************************************************* QUESTION ************************************************************************************/

/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
*/

/************************************************************************** DFS *************************************************************************************/

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int initialcolor) {
     //checking for the conditions if it's not out of bound and if the element is same as initial color we will update that element's color
        if(sr >= 0 && sc >= 0 && sr < image.size() && sc < image[0].size() && image[sr][sc] == initialcolor) {
            image[sr][sc] = color; //updating current element's color
            dfs(image, sr - 1, sc, color, initialcolor); //dfs call in all four directions
            dfs(image, sr, sc + 1, color, initialcolor);
            dfs(image, sr, sc - 1, color, initialcolor);
            dfs(image, sr + 1, sc, color, initialcolor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     //store the initial color
        int initialcolor = image[sr][sc];

     //if the source is already same as the color we will simply return the image
        if(initialcolor == color) {
            return image;
        }

     //we will call dfs of all the directions
        dfs(image, sr, sc, color, initialcolor);
        return image;
    }
};

/**************************************************************************** BFS ************************************************************************************/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

     //if amage array only conists of a single row or column or is empty
        if(m == 0 || n == 0) {
            return image;
        }

     //creatig a queue to store all the elements which needs to be changed
        queue<pair<int, int>> q;
        int initialcolor = image[sr][sc]; //storing the initial color
        if(initialcolor == color) {
            return image;  // if the initial color is same as the color that needs to be changed
        }
        q.push({sr, sc}); 

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            image[i][j] = color;  //updating color of current element
            q.pop();

            int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};   //direction array for all four directions

            for(int k = 0; k < 4; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(x >= 0 && y >= 0 && x < m && y < n && image[x][y] == initialcolor) {
                    q.push({x, y});
                }
            }
        }

        return image;

    }
};
