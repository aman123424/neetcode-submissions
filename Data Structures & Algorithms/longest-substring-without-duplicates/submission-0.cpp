class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;

        int start = 0, end = 0;
        int longest = 0;
        int length = 0;

        while(end < s.size()) {
            if(count[s[end]] > 0) {
                count[s[start]]--;
                start++;
                length--;
                continue;
            }

            count[s[end]]++;
            length++;
            longest = max(length, longest);
            end++;
        }

        return max(length, longest);

    }
};
