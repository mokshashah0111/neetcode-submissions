class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check for cols

        for(int rows = 0; rows<9;rows++){
            unordered_set<char>seen;
            for(int i =0; i<9;i++){
                if(board[rows][i] == '.')continue;
                if(seen.count(board[rows][i]))return false;
                seen.insert(board[rows][i]);
            }
        }
        
        //check rows;
        for(int cols =0;cols<9;cols++){
            unordered_set<char>seen;
            for(int i =0; i<9;i++){
                if(board[i][cols] == '.')continue;
                if(seen.count(board[i][cols]))return false;
                seen.insert(board[i][cols]);
            }
        }
        
        //check squares
        for(int sq =0;sq<9;sq++){
            unordered_set<char>seen;
            for(int i= 0;i<3;i++){
                for(int j =0;j<3;j++){
                    int row = ((sq/3)*3) + i;
                    int col = ((sq%3)*3) + j;

                    if(board[row][col] == '.')continue;
                    if(seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
