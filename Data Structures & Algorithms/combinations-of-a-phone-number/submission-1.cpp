class Solution {
public:
    unordered_map<char, string> map;
    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        
        if(digits.empty()) return ans;
        string curr;
        recursive(0, curr, digits);
        return ans;
    }

    void recursive(int ind, string& curr, string& digits) {
        if(ind >= digits.size()) {
            ans.push_back(curr);
            return;
        }

        for(auto it : map[digits[ind]]) {
            curr += it;
            recursive(ind + 1, curr, digits);
            curr.pop_back();
        }
    }
};
