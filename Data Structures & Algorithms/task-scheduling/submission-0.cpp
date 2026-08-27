class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        for(auto task : tasks) {
            mpp[task]++;
        }

        priority_queue<int> pq;
        for(auto it : mpp) {
            pq.push(it.second);
        } 

        int res = 0;

        while(!pq.empty()) {
            vector<int> ls;

            for(int i = 0; i <= n && !pq.empty(); i++) {
                ls.push_back(pq.top());
                pq.pop();
            }

            for(int freq : ls) {
                if(freq > 1) {
                    pq.push(freq - 1);
                }
            }

            res += pq.empty() ? ls.size() : n + 1;
        }

        return res;
    }
};
