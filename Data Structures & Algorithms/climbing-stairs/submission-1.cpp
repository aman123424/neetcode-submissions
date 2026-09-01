class Solution {
public:
    vector<int> cache;
    int climbStairs(int n) {
        cache.resize(n, -1);
        return dfs(n, 0);
    }

    int dfs(int n, int i) {
        if (i >= n) return i == n;
        if (cache[i] != -1) return cache[i];
        return cache[i] = dfs(n, i + 1) + dfs(n, i + 2);
    }
};
