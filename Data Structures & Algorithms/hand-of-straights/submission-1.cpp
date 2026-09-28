class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) {
            mpp[hand[i]]++;
        }

        for(int i = 0; i < n; i++) {
            int start = hand[i];

            while(mpp[start - 1] > 0) {
                start--;
            }

            while (start <= hand[i]) {
                while (mpp[start] > 0) {
                    for (int i = start; i < start + groupSize; i++) {
                        if (mpp[i] == 0) return false;
                        mpp[i]--;
                    }
                }
                start++;
            }
        }

        return true;
    }
};
