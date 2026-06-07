class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();
        stack<int> s;

        vector<int> res;

        for (int i = 0; i < n; i++) {

            bool destroyed = false;

while (!s.empty() && s.top() > 0 && asteroids[i] < 0) {

    if (s.top() < abs(asteroids[i])) {
        s.pop();             
    }
    else if (s.top() == abs(asteroids[i])) {
        s.pop();              
        destroyed = true;
        break;
    }
    else {
        destroyed = true;    
        break;
    }
}

            if (!destroyed) {
                s.push(asteroids[i]);
            }
        }

        while (!s.empty()) {
            int element = s.top();
            s.pop();
             res.push_back(element);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
