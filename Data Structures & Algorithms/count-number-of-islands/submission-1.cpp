class Solution {
public:
    bool isValid(int r, int c, vector<vector<char>>& grid){
        return r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] == '1';
    }
    void bfs(int row, int col, vector<vector<char>>& grid, int& count){
        queue<pair<int,int>>q;
        q.push({row,col});
        int delrow[] = {0,-1,0,1};
        int delcol[] = {-1,0,1,0};
        
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            for(int i =0; i<4;i++){
                int nr = r+delrow[i];
                int nc = c+delcol[i];
                if(isValid(nr,nc,grid)){
                    grid[nr][nc] ='0';
                    q.push({nr,nc});
                }
            }
        }
        count++;
    }
    int numIslands(vector<vector<char>>& grid) {
        //start with 0,0 --> whenever you encounter 1, run a dfs or bfs traversal, increase the count and change the corresponding value to 0 to avoid duplicates
        int rows = grid.size();
        int cols = grid[0].size();
        int count =0;
        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    bfs(i,j,grid,count);
                }
            }
        }
        return count;
    }
};
