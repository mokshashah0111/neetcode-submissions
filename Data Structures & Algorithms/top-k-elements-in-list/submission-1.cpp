class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int& i: nums){
            freq[i]++;
        }
        int size = freq.size();
        vector<vector<int>>bucket(nums.size()+1);
        for(auto& it: freq){
            bucket[it.second].emplace_back(it.first);
        }
        vector<int>ans;
        for(int i =bucket.size()-1;i>=0;i--){
            vector<int>elements = bucket[i];
            for(int& ele: elements){
                ans.emplace_back(ele);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
