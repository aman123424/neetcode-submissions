class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first = false, second = false, third = false;

        for(int i = 0; i < triplets.size(); i++) {
            vector<int> triplet = triplets[i];

            if(triplet[0] == target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                first = true;
            }

            if(triplet[0] <= target[0] && triplet[1] == target[1] && triplet[2] <= target[2]) {
                second = true;
            }

            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] == target[2]) {
                third = true;
            }
        }

        return first && second && third;
    }
};
