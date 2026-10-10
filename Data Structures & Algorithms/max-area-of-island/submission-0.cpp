class Solution {
public:
    bool isValid(int r,int c, vector<vector<int>>& grid){
        return r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] ==1;
    }
    int bfs(int row, int col, vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        int count =1;
        q.push({row,col});
        int delrow[] = {0,-1,0,1};
        int delcol[] = {1,0,-1,0};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i=0; i<4;i++){
                int nr = r+delrow[i];
                int nc = c+ delcol[i];
                if(isValid(nr,nc,grid)){
                    grid[nr][nc] =0;
                    q.push({nr,nc});
                    count++;
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        for(int i =0;i<rows;i++){
            for(int j = 0; j<cols;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int area= bfs(i,j,grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
