class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int& i: nums){
            freq[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;

        for(auto& f: freq){
            minHeap.push({f.second,f.first});
            if(minHeap.size() >k){
                minHeap.pop();
            }
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.emplace_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};
