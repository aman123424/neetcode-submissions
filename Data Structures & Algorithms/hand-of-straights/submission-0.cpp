class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) {
            mpp[hand[i]]++;
        }

        sort(hand.begin(), hand.end());

        for(int i = 0; i < n; i++) {
            if(mpp[hand[i]] == 0) {
                continue;
            } else {
                for(int j = 0; j < groupSize; j++) {
                    if(mpp[hand[i] + j] > 0) {
                        mpp[hand[i] + j]--;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
