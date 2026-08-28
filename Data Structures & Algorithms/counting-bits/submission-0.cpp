class Solution {
public:
    int count(int n) {
        int ans = 0;
        while(n) {
            if(n&1) ans++;
            n = n >> 1;
        }
        return ans;
    }

    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            res[i] = count(i);
        }

        return res;
    }
};
