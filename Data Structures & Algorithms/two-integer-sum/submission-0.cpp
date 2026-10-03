class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int,int>seen;

        for(int i =0;i<size;i++){
            int current= nums[i];
            int rem = target-current;

            if(seen.find(rem)!= seen.end()){
                return {seen[rem],i};
            }
            seen[current] = i;
        }
        return {};
    }
};
