class Solution {
public:
    int helper(int index, vector<int>& memo,vector<int>& cost){
        if(index>=cost.size()) return 0;
        if(memo[index] != -1) return memo[index];
        memo[index] = cost[index] + min(helper(index+1,memo,cost), helper(index+2,memo,cost));
        return memo[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>memo(n,-1);
        return min(helper(0,memo,cost), helper(1,memo,cost));
    }
};
