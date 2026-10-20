class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        int j = -1;

        for (int& a : asteroids) {
            while (j >= 0 && asteroids[j] > 0 && a < 0) {
                if (asteroids[j] > abs(a)) {
                    a = 0;
                    break;
                } else if (asteroids[j] == abs(a)) {
                    j--;
                    a = 0;
                    break;
                } else {
                    j--;
                }
            }
            if (a != 0) {
                asteroids[++j] = a;
            }
        }

        asteroids.resize(j + 1);
        return asteroids;
    }
};