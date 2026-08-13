class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> leftProducts;
        unordered_map<int, int> rightProducts;

        int product = 1;

        for(int i = 0; i < n; i++) {
            product = nums[i] * product;
            leftProducts[i] = product;
        }

        product = 1;
        for(int i = n - 1; i >= 0; i--) {
            product = product * nums[i];
            rightProducts[i] = product;
        }

        vector<int> result;
        for(int i = 0; i < n; i++) {
            int prd = 1;
            if(leftProducts.find(i - 1) != leftProducts.end()) {
                prd = prd * leftProducts[i - 1];
            }
            if(rightProducts.find(i + 1) != rightProducts.end()) {
                prd = prd * rightProducts[i + 1];
            }
            result.push_back(prd);
        }

        return result;
    }
};
