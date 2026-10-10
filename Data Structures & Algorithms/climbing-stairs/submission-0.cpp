class Solution {
public:
    int helper(int index, vector<int>& memo){
        if(index<0) return 0;
        if(memo[index] != -1) return memo[index];
        memo[index] = helper(index-1,memo) + helper(index-2,memo);
        return memo[index];
    }
    int climbStairs(int n) {
        if(n==1 || n==2) return n;
        vector<int>memo(n,-1);
        memo[0] = 1;
        memo[1] =2 ;
        return helper(n-1,memo);
    }
};
