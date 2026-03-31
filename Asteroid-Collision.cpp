1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& as) {
4        stack<int> s;
5        for (int i = 0; i < as.size(); i++) {
6            bool bacha = true;
7            while (!s.empty() && (s.top() > 0 && as[i] < 0)) {
8                if (abs(s.top()) > abs(as[i])) {
9
10                    bacha = false;
11                    break;
12                } else if (abs(s.top()) < abs(as[i])) {
13
14                    s.pop();
15
16                } else {
17
18                    bacha = false;
19                    s.pop();
20                    break;
21                }
22            }
23            if (bacha) {
24                s.push(as[i]);
25            }
26        }
27        vector<int> ans;
28        while (!s.empty()) {
29            ans.push_back(s.top());
30            s.pop();
31        }
32        reverse(ans.begin(), ans.end());
33        return ans;
34    }
35};