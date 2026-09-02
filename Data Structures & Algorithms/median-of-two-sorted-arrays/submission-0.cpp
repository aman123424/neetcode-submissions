class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();

        int medianIndex = total/2;

        int i = 0, j = 0;
        vector<int> temp;

        while(i < nums1.size() && j < nums2.size()) {
            if(temp.size() > medianIndex) {
                break;
            }

            if(nums1[i] < nums2[j]) {
                temp.push_back(nums1[i++]);
            } else {
                temp.push_back(nums2[j++]);
            }
        }

        while(i < nums1.size()) {
            if(temp.size() > medianIndex) {
                break;
            }

            temp.push_back(nums1[i++]);
        }

        while(j < nums2.size()) {
            if(temp.size() > medianIndex) {
                break;
            }

            temp.push_back(nums2[j++]);
        }

        if(total % 2) return (double)temp.back();
        return (temp.back() + temp[temp.size() - 2]) / 2.0;
    }
};
