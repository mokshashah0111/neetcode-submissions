class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>freq;
        vector<vector<string>>ans;
        
        for(string str: strs){
            vector<int>count(26,0);
            for(char c: str){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for(int i: count){
                key += ','+ to_string(i);
            }

            freq[key].push_back(str);
        }
        for(auto& anagrams: freq){
            ans.emplace_back(anagrams.second);
        }
        return ans;
    }
};
