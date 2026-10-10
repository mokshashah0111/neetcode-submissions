class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if(size==0) return 0;
        unordered_map<int,int>boundaries;
        int len = 1;
        for(int& num: nums){
            if(!boundaries[num]){
                int left = boundaries[num-1];
                int right = boundaries[num+1];
                boundaries[num] = left+right+1;
                boundaries[num-left] = boundaries[num];
                boundaries[num+right] = boundaries[num];
                len = max(len, boundaries[num]);
            }
        }
        return len;
        
    }
};
