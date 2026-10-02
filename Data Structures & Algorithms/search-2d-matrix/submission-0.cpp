class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low =0;
        int high = (rows*cols)-1;

        while(low<=high){
            int mid = low +((high-low)/2);
            int r = mid/cols;
            int c= mid%cols;

            if(matrix[r][c] < target){
                low = mid+1;
            }
            else if(matrix[r][c] == target) return true;
            else high = mid-1;
        }
        return false;
    }
};
