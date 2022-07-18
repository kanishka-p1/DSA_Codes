//                                                                      QUESTION

/*
There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.

Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note :  We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.




Input Format

1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, number of circles.
4th argument given is an Integer R, radius of each circle.
5th argument given is an Array A of size N, where A[i] = x cordinate of ith circle
6th argument given is an Array B of size N, where B[i] = y cordinate of ith circle
Output Format

Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).
Constraints

0 <= x, y, R <= 100
1 <= N <= 1000
Center of each circle would lie within the grid
For Example

Input:
    x = 2
    y = 3
    N = 1
    R = 1
    A = [2]
    B = [3]
Output:
    NO
   
Explanation:
    There is NO valid path in this case
*/

//                                                                            ANSWER


//all 8-direction move
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {0, 1, -1, 1, -1, 0, 1, -1};

string Solution::solve(int x, int y, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool>> mat(x + 1, vector<bool>(y + 1));
    
    //check each point is inside circle or not
    for(int i = 0; i <= x; i++) {
        for(int j = 0; j <= y; j++) {
            bool flag = false;
            for(int k = 0; k < E.size(); k++) {
                //check if the box lies inside the circle
                if((E[k] - i) * (E[k] - i) + (F[k] - j) * (F[k] - j) <= D * D) {
                    flag = true;
                    break;
                }
            }
            mat[i][j] = flag;
        }
    }
    
    //if starting index is inside the circle
    if(mat[0][0] == true) {
        return "NO";
    }
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    //using the same matrix to make visited
    mat[0][0] = true;
    
    while(!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        
        //reach our destination
        if(top.first == x && top.second == y) {
            return "YES";
        }
        
        //go in all possible 8 directions
        for(int i = 0; i < 8; i++) {
            int newx = dx[i] + top.first;
            int newy = dy[i] + top.second;
            
            //if inside the rectangle and not inside the circle
            if(newx >= 0 && newx <= x && newy >= 0 && newy <= y && mat[newx][newy] == false) {
                q.push({newx, newy});
                
                //visit the coordinates
                mat[newx][newy] = true;
            }
        }
    }
    
    return "NO";
}
