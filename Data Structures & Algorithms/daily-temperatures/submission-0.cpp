class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int>result(size,0);
        stack<pair<int,int>>st;
        for(int i = 0;i<size;i++){//0...1....2...3...4....5...6
            while(i>0 && !st.empty() && st.top().first < temperatures[i]){
                int waitDays = i-st.top().second;//1...1...1...2....4
                result[st.top().second] = waitDays;//{1,4,1,2,1,0,0}
                st.pop();//{}
            }
            st.push({temperatures[i],i});//{{30,0}}....{{38,1}}....{{38,1},{40,5}}
        }
        return result;
    }
};
