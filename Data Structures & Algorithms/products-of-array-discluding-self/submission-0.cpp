class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //1,2,4,6
        //1,1,2,8
        //1,6,24,48
        //
        int n = nums.size();
        vector<int>prefix(nums.size(),1);
        vector<int>suffix(nums.size(),1);

        for(int i=1; i<n;i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        for(int i = n-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }
        vector<int>result(nums.size(),0);
        for(int i =0 ;i<n;i++){
            result[i] = prefix[i]*suffix[i];
        }
        return result;

    }
};
