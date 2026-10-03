class TimeMap {
private:
    vector<vector<int>> timeStamps;
    vector<vector<string>> values;
    unordered_map<string, int> keyIndex;

public:
    TimeMap() = default;

    void set(string key, string value, int timestamp) {
        auto it = keyIndex.find(key);

        int index;

        if (it == keyIndex.end()) {
            index = timeStamps.size();
            keyIndex[key] = index;

            timeStamps.push_back({});
            values.push_back({});
        } else {
            index = it->second;
        }

        timeStamps[index].push_back(timestamp);
        values[index].push_back(value);
    }

    string get(string key, int timestamp) {
        auto it = keyIndex.find(key);

        if (it == keyIndex.end()) {
            return "";
        }

        int index = it->second;
        const vector<int>& timestamps = timeStamps[index];

        int left = 0;
        int right = timestamps.size() - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (timestamps[mid] <= timestamp) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (answer == -1) {
            return "";
        }
        return values[index][answer];
    }
};