class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string encodedString;
        for(auto s : strs) {
            encodedString.append(to_string(s.size()));
            encodedString.push_back(',');
        }

        encodedString += "#";
        for(auto s : strs) {
            encodedString += s;
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<int> sizes;
        int i = 0;

        while(s[i] != '#') {
            int j = i;
            while(s[j] != ',') {
                j++;
            }
            sizes.push_back(stoi(s.substr(i, j - i)));
            i = j + 1;
        }
        
        i++;
        vector<string> result;
        
        for(int sz : sizes) {
            result.push_back(s.substr(i, sz));
            i += sz;
        }

        return result;
    }
};
