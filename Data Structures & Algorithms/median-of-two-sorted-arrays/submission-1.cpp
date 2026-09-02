class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();

        int medianIndex = total/2;

        int i = 0, j = 0;
        int count = 0, two = 0, one = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if(count > medianIndex) {
                break;
            }

            count++;
            two = one;

            if(nums1[i] < nums2[j]) {
                one = nums1[i++];
            } else {
                one = nums2[j++];
            }
        }

        while(i < nums1.size()) {
            if(count > medianIndex) {
                break;
            }

            count++;
            two = one;
            one = nums1[i++];
        }

        while(j < nums2.size()) {
            if(count > medianIndex) {
                break;
            }

            count++;
            two = one;
            one = nums2[j++];
        }

        if(total % 2) return (double)one;
        return (one + two) / 2.0;
    }
};
