class Solution {
public:
    int sumOfSquares(int n) {
        int sum = 0;

        while(n > 0) {
            int digit = n%10;
            sum += (digit * digit);
            n = n/10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_map<int, int> mpp;

        while(n) {
            int sum = sumOfSquares(n);

            if(sum == 1) return true;

            if(mpp.find(sum) != mpp.end()) {
                return false;
            }
            mpp[sum]++;
            n = sum;
        }

        return false;
    }
};
