class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        
        auto comp = [](const pair<int, int> a, const pair<int, int> b) {
            return b.second > a.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        for(auto pair : mpp) {
            pq.push(pair);
        }

        vector<int> result;

        for(int i = 0; i < k; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
