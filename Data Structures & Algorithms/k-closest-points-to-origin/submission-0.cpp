struct Compare {
        bool operator()(const pair<int, vector<int>>& a,
                    const pair<int, vector<int>>& b) {
            return a.first > b.first;
        }
};

class Solution {
public:
    int calculateDistance(int x, int y) {
        return x*x + y*y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
    pair<int, vector<int>>,
    vector<pair<int, vector<int>>>,
    Compare
> pq;

        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int distance = calculateDistance(x,y);

            pq.push({distance, {x,y}});
        }

        vector<vector<int>> res;
        
        while(k) {
            vector<int> point = pq.top().second;
            pq.pop();
            res.push_back(point);
            k--;
        }

        return res;
    }
};
