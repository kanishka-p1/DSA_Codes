struct cell {
    int x;
    int y;
    int dist;
    cell() {}
    cell(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

bool isinside(int x, int y, int A, int B) {
    if(x >= 0 && y >= 0 && x < A && y < B) {
        return true;
    }
    return false;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int dx[] = {2, 1, -1, -2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    queue<cell> q;
    cell src(C - 1, D - 1, 0);
    
    vector<vector<bool>> visited(A, vector<bool> (B, false));
    
    visited[C - 1][D - 1] = true;
    q.push(src);
    
    int x, y, dist;
    
    while(!q.empty()) {
        cell c = q.front();
        q.pop();
        if(c.x == E - 1 && c.y == F - 1) {
            return c.dist;
        }
        for(int i = 0; i < 8; i++) {
            x = c.x + dx[i];
            y = c.y + dy[i];
            
            if(isinside(x, y, A, B) && !visited[x][y]) {
                visited[x][y] = true;
                cell t(x, y, c.dist + 1);
                q.push(t);
            }
        }
    }
    
    return -1;
}
